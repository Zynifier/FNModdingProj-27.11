// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapDefender.generated.h"

class AActor;
class AFortAIPawn;
class AFortPlayerController;
class AFortPlayerStateZone;
class UFortAccountItem;
class UFortDefenderItem;
class UFortDefenderItemDefinition;
class UFortWorldItem;

UENUM()
enum class EFortDefenderInteractionError : uint8
{
	None = 0,
	Obstructed = 1,
	NoEditPermission = 2,
	UsedByAnotherPlayer = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDefenderPawnOrItemSet);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapDefender : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void ClearCurrentDefender(bool bForceKillDefender);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void DeployDefender(const AFortPlayerController* ItemSelectorPC, const UFortDefenderItem* InDefenderItem, const FName& InDefenderSquadId, const UFortWorldItem* WeaponToGive, const int32 AmmoQuantity);

	UFUNCTION(BlueprintImplementableEvent)
	FTransform GetDefenderSpawnTransform() const;

	UFUNCTION(BlueprintCallable, Category="Defender")
	FText GetLastInteractErrorText();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void RemoveCurrentDefender(AFortPlayerStateZone* RequestingPlayer, bool bRemovalCausedByPlayerJoin);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Defender")
	void SupplyDefender(const UFortWorldItem* WeaponToGive, const int32 AmmoQuantity);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Defender")
	UFortWorldItem* TakeWeaponAwayFromDefender(UFortWorldItem* WeaponToTakeAway);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Defender")
	EFortDefenderInteractionError LastInteractError;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRep_DefenderItemDefinition();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRep_DefenderPawn();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Defender")
	AFortAIPawn* SpawnDefenderfromItem(UFortAccountItem* DefenderItem, const FName& DefenderSquadId, const FTransform& SpawnTransform, AActor* InOwner);

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_DefenderPawn, Category="Defender")
	TObjectPtr<AFortAIPawn> DefenderPawn;

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_DefenderItemDefinition, Category="Defender")
	TObjectPtr<UFortDefenderItemDefinition> DefenderItemDefinition;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Defender")
	int32 DefenderItemLevel;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Defender")
	FDefenderPawnOrItemSet DefenderPawnOrItemSet;

};

