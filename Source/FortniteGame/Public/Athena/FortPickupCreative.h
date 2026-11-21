// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPickupAthena.h"
#include "Building/BuildingTypes.h"
#include "FortPickupInstigatorInterface.h"
#include "FortTeamActorInterface.h"
#include "FortPickupCreative.generated.h"

class AFortPawn;
class UFortCreativeCostComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickupReplicated);

UCLASS()
class AFortPickupCreative : public AFortPickupAthena, public IFortTeamActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool BlueprintClassAllowed(const AFortPawn* Pawn) const;

	UFUNCTION(BlueprintNativeEvent)
	bool BlueprintTeamAllowed(const AFortPawn* Pawn) const;

	UFUNCTION(BlueprintPure)
	float GetAccentColorParam() const;

	UFUNCTION(BlueprintCallable)
	void GivePickupToPawn(AFortPawn* Pawn, bool DestoryAfterPickup = true);

	UFUNCTION(BlueprintCallable)
	void SetItemResourceCost(const EFortResourceType::Type ResourceType, const int32 Cost);

	UPROPERTY(BlueprintReadWrite, Replicated, Export, Category="Cost", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeCostComponent> CostComponent;

	UPROPERTY(BlueprintReadWrite, Category="FortPickupCreative")
	bool bPickupOnTouch;

protected:
	UFUNCTION()
	void OnPickupInstigatorDataChanged(int32 TrackedIndex);

	UFUNCTION()
	void OnPickupInstigatorDataRemoved(int32 TrackedIndex);

	UFUNCTION()
	void OnRep_PickupInstigatorIndex();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PickupInstigatorIndex)
	int32 CachedPickupInstigatorHandle;

	UPROPERTY(Transient)
	FPickupInstigatorData CachedInstigatorData;

	UPROPERTY(EditDefaultsOnly, Category="FortPickupCreative")
	bool bUseOverrideDespawnTime;

	UPROPERTY(EditDefaultsOnly, Category="FortPickupCreative", meta=(EditCondition="bUseOverrideDespawnTime"))
	float OverrideDespawnTime;

	UPROPERTY(BlueprintAssignable)
	FOnPickupReplicated OnAccentColorParamChanged;

};

