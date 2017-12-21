// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacterBase.generated.h"

UCLASS()
class ARPGSTARTER_API AMyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	UFUNCTION(BlueprintCallable, Category = "ARPG Starter")
	void GetPlayerLookAtLocation(FVector& LookAt, float& Alpha);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ARPG Starter")
	class USphereComponent* OverlapSphere;

private:
	AActor* FindNearestTarget();
};
