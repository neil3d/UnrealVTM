// Fill out your copyright notice in the Description page of Project Settings.

#include "ARPGStarter.h"
#include "ARPGStarterGameMode.h"

void AARPGStarterGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass != nullptr)
	{
		UUserWidget* HUDWidget = CreateWidget<UUserWidget>(
			GetWorld(),
			HUDWidgetClass
			);
		if (HUDWidget != nullptr)
		{
			HUDWidget->AddToViewport();
		}
	}
}