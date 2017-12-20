// Fill out your copyright notice in the Description page of Project Settings.

#include "MyShip.h"
#include "ShipWeapon.h"


// Sets default values
AShipWeapon::AShipWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShipWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

