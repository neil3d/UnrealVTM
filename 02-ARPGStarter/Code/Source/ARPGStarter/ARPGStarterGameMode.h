// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Blueprint/UserWidget.h"

#include "ARPGStarterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARPGSTARTER_API AARPGStarterGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
	virtual void BeginPlay() override;

public:
	/** HUD Widget class this game uses. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ARPG Starter")
	TSubclassOf<class UUserWidget> HUDWidgetClass;
		
};
