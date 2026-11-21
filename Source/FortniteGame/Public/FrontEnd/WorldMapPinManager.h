// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortInitializationInterface.h"
#include "WorldMapPinManager.generated.h"

class AFortStaticMeshActor;
class AWorldMapPin;

UCLASS(BlueprintType)
class AWorldMapPinManager : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="WorldMap")
	AWorldMapPin* CreateWorldMapPin(const FString& TheaterId);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	TObjectPtr<AFortStaticMeshActor> WorldMapMesh;

	UPROPERTY(BlueprintReadOnly, Category="Properties")
	TArray<TObjectPtr<AWorldMapPin>> CurrentPins;

};

