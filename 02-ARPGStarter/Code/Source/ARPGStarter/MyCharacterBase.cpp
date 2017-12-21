// Fill out your copyright notice in the Description page of Project Settings.

#include "ARPGStarter.h"
#include "MyCharacterBase.h"


// Sets default values
AMyCharacterBase::AMyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapShpere"));
	OverlapSphere->AttachTo(RootComponent);
	OverlapSphere->SetSphereRadius(300);
}

// Called when the game starts or when spawned
void AMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyCharacterBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AMyCharacterBase::GetPlayerLookAtLocation(FVector& LookAt, float& Alpha)
{
	LookAt = FVector::ZeroVector;
	Alpha = 0;

	AActor* Target = FindNearestTarget();

	if (Target != nullptr)
	{
		LookAt = Target->GetActorLocation();
		LookAt.Z += BaseEyeHeight * 2;

		Alpha = 1;
	}
}

AActor* AMyCharacterBase::FindNearestTarget()
{
	TArray<AActor*> OverlapActors;
	OverlapSphere->GetOverlappingActors(OverlapActors);

	AActor* NearestTarget = nullptr;
	float NearestDist = 1024 * 1024;

	FName TagTarget(TEXT("PlayerTarget"));

	for (int i = 0; i < OverlapActors.Num(); i++)
	{
		AActor* actor = OverlapActors[i];
		if (actor->ActorHasTag(TagTarget))
		{
			float dist = actor->GetDistanceTo(this);
			if (dist < NearestDist)
			{
				NearestTarget = actor;
				NearestDist = dist;
			}
		}
	}

	return NearestTarget;
}