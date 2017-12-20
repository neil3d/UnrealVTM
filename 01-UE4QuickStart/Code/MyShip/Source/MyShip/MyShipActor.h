// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "ShipWeapon.h"
#include "MyShipActor.generated.h"

UCLASS()
class MYSHIP_API AMyShipActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	// 构造函数
	AMyShipActor();

	// 游戏开始时调用，相当于Unity的Start()
	virtual void BeginPlay() override;
	
	// 每帧调用，相当Unity的Update()
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category="MyShipGame")
    float WaveStrength;

	UPROPERTY(VisibleAnywhere, Category = "MyShipGame")
	FVector2D WaveOffset;

	/** 舰炮类型 */
	UPROPERTY(EditAnywhere, Category = "MyShipGame")
	TSubclassOf<AShipWeapon> WeaponType;


	virtual void PostInitProperties() override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

private:
	FVector2D WaveFactor;
};
