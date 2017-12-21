// Fill out your copyright notice in the Description page of Project Settings.

#include "VRStarter.h"
#include "VRPlayerBase.h"


// Sets default values
AVRPlayerBase::AVRPlayerBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVRPlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRPlayerBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AVRPlayerBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//-- 测试用的鼠标转动操作
	// InitializeDefaultPawnInputBindings
	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Turn", EKeys::MouseX, 1.f));
	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("LookUp", EKeys::MouseY, -1.f));

	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MouseLMB", EKeys::LeftMouseButton));

	// Action Bind
	InputComponent->BindAxis("Turn", this, &AVRPlayerBase::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AVRPlayerBase::AddControllerPitchInput);

	InputComponent->BindAction("MouseLMB", IE_Pressed, this, &AVRPlayerBase::OnTouchTap);

	//-- Touch
	InputComponent->BindTouch(IE_Pressed, this, &AVRPlayerBase::OnTouchBegin);
	InputComponent->BindTouch(IE_Released, this, &AVRPlayerBase::OnTouchEnd);
	InputComponent->BindTouch(IE_Repeat, this, &AVRPlayerBase::OnFingerMove);
}

void AVRPlayerBase::OnTouchBegin(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StartTouchDragLocation = FVector2D(Location);
		LastTouchDragLocation = StartTouchDragLocation;
	}
}

void AVRPlayerBase::OnTouchEnd(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		LastTouchDragLocation = FVector2D(Location);
		if (FVector2D::Distance(StartTouchDragLocation, LastTouchDragLocation) < 4)
		{
			OnTouchTap();
		}
		
		LastTouchDragLocation = FVector2D::ZeroVector;
	}
}

static const float TouchDragRotationScale = 0.1f;

void AVRPlayerBase::OnFingerMove(ETouchIndex::Type FingerIndex, FVector Location)
{
	if ((FingerIndex == ETouchIndex::Touch1) && (!LastTouchDragLocation.IsZero()))
	{
		FVector2D const DragDelta = (FVector2D(Location) - LastTouchDragLocation) * TouchDragRotationScale;

		OnTouchMove(DragDelta);

		LastTouchDragLocation = FVector2D(Location);
	}
}