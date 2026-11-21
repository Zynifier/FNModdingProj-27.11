// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortHLODStaticMeshActor.generated.h"

class UStaticMesh;
class UStaticMeshComponent;

UCLASS(MinimalAPI)
class AFortHLODSMActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="HLODSMActor")
	FName GetActorFName() const;

	UPROPERTY(VisibleAnywhere, Category="FortHLODSMActor")
	FName ActorFName;

	UPROPERTY(VisibleAnywhere, Category="FortHLODSMActor")
	FVector UniqueWorldLocation;

	UPROPERTY(VisibleAnywhere, Category="FortHLODSMActor")
	uint8 bIsDynamic : 1;

	UPROPERTY(VisibleAnywhere, Category="FortHLODSMActor")
	uint8 bStartHidden : 1;

protected:
	UPROPERTY()
	float MaxDrawDistanceMultiplier;

	UPROPERTY()
	TSoftObjectPtr<UStaticMesh> HLODStaticMesh;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY()
	FName OverlayLevelName;

};

