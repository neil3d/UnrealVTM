// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "VRPlayerBase.generated.h"

UCLASS()
class VRSTARTER_API AVRPlayerBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPlayerBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//-- Touch Event
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="VRStarter")
	void OnTouchTap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="VRStarter")
	void OnTouchMove(FVector2D DragDelta);
	
private:

	/** The normalized screen location when a drag starts */
	FVector2D LastTouchDragLocation;
	FVector2D StartTouchDragLocation;

	void OnTouchBegin(ETouchIndex::Type FingerIndex, FVector Location);
	void OnTouchEnd(ETouchIndex::Type FingerIndex, FVector Location);
	void OnFingerMove(ETouchIndex::Type FingerIndex, FVector Location);
};
