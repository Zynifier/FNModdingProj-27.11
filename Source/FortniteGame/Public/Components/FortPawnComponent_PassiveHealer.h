// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Components/FortPawnComponent.h"
#include "FortItemAndCount.h"
#include "FortPawnComponent_PassiveHealer.generated.h"

class AFortPawn;
class UBoxComponent;
class UDataTable;
class UFortGameStateComponent_AffiliationManager;
class UFortItemDefinition;
class UFortWorldItem;
class UGameplayEffect;
class UWidgetComponent;

USTRUCT()
struct FFortBotPassiveHealerActivityDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activity")
	FPrimaryAssetId EmotePrimaryAssetId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activity")
	FText InteractText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activity")
	TArray<FText> GreetingTexts;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activity")
	bool bEnabled;

};

USTRUCT()
struct FFortPassiveHealerPawnInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> Pawn;

	UPROPERTY(Transient)
	bool bEmoteStarted;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_PassiveHealer : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Passive Healer")
	FText GetGreetingPassiveHealingText() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Passive Healer")
	void Start();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Passive Healer")
	void Stop();

private:
	UFUNCTION()
	void OnHealedPlayerStartedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void OnHealedPlayerStoppedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void OnRep_PassiveHealingRunning();

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat PassiveHealerGreetingDistance;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat PassiveHealerGreetingDuration;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UDataTable> PassiveHealerActivitiesTable;

	UPROPERTY(EditAnywhere, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsToApply;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FItemAndCount HealItem;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat HealingIntervalDuration;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat HealItemEquipDuration;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat HealItemThrowHoldDuration;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat HealItemWaitAfterThrowDuration;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Passive Healer")
	FName PassiveHealerInteractionCollisionProfile;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Passive Healer")
	FVector PassiveHealerInteractionBoxExtent;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Passive Healer")
	FVector PassiveHealerInteractionBoxOffset;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UWidgetComponent> GreetingTextWidgetComponentClass;

	UPROPERTY(EditAnywhere, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FDataTableRowHandle OverrideLootInfo;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> AffiliationManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> InteractCollisionComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PassiveHealingRunning)
	uint8 bPassiveHealingRunning : 1;

	UPROPERTY(Transient, Replicated)
	FPrimaryAssetId SelectedEmotePrimaryAssetId;

	UPROPERTY(Transient, Replicated)
	FText SelectedInteractText;

	UPROPERTY(Transient, Replicated)
	FText SelectedGreetingText;

	UPROPERTY(Transient)
	float GreetingDistanceSqr;

	UPROPERTY(Transient)
	TArray<FFortPassiveHealerPawnInfo> HealingPawns;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidgetComponent> GreetingTextWidgetComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> FortWorldHealItem;

};

