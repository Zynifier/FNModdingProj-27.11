// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "FortClientOnlyActor.h"
#include "FortTeamActorInterface.h"
#include "BuildingWeakSpot.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FBuildingWeakSpotData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<UObject> ParentObject;

	UPROPERTY(BlueprintReadOnly, Category="BuildingWeakSpotData")
	FVector_NetQuantizeNormal Normal;

	UPROPERTY(BlueprintReadOnly, Category="BuildingWeakSpotData")
	FVector_NetQuantize10 Position;

	UPROPERTY(BlueprintReadOnly, Category="BuildingWeakSpotData")
	int32 HitCount;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Navigation", "Replication"))
class ABuildingWeakSpot : public AFortClientOnlyActor, public IFortTeamActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Deactivate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFadeOut();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHit();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartDirectionEffect();

	UPROPERTY(Transient)
	TWeakObjectPtr<UObject> ParentObject;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	uint8 bHit : 1;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	uint8 bFadeOut : 1;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	uint8 bActive : 1;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	int32 HitCount;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeakSpot")
	int32 MaxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeakSpot")
	FVector StartingLocation;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	FVector HitNormal;

	UPROPERTY(BlueprintReadOnly, Category="WeakSpot")
	TEnumAsByte<EPhysicalSurface> PhysicalSurfaceType;

};

