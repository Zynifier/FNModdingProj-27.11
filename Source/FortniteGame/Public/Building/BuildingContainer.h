// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/BuildingSMActor.h"
#include "Building/BuildingTimeOfDayLights.h"
#include "FortRarityEnum.h"
#include "FortSoundIndicatorInterface.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "BuildingContainer.generated.h"

class ABuildingContainer;
class AFortPawn;
class AFortPickup;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class UAudioComponent;
class UCurveFloat;
class UFortSoundIndicatorComponent;
class UFortWorldItemDefinition;
class UMaterialInterface;
class USoundCue;
class UStaticMesh;
enum class EFortSoundIndicatorTypes : uint8;

UENUM()
enum class ECalendarDrivenState : uint8
{
	ForceEnable = 0,
	ForceDisable = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnContainerRandomUpgradeApplied, ABuildingContainer*, BuildingContainer, int32, UpgradeIndex, const FName&, UpgradeLootTierGroup);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContainerSearchedStateChanged, ABuildingContainer*, BuildingContainer, bool, bSearched);

USTRUCT()
struct FFortSearchBounceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector3f BounceNormal;

	UPROPERTY()
	uint32 SearchAnimationCount;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerPawn> SearchingPawn;

};

USTRUCT()
struct FLootTierGroupTagOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LootTierGroupTagOverride")
	FScalableFloat IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="LootTierGroupTagOverride")
	FName OverrideLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="LootTierGroupTagOverride")
	FGameplayTagQuery PlayerTagQuery;

};

USTRUCT()
struct FRandomUpgradeCalendarData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RandomUpgradeCalendarData")
	ECalendarDrivenState ReactionWhenEventIsPresent;

	UPROPERTY(EditAnywhere, Category="RandomUpgradeCalendarData")
	FString EventName;

};

USTRUCT()
struct FRandomUpgradeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RandomUpgradeData")
	FName LootTierGroupIfApplied;

	UPROPERTY(EditAnywhere, Category="RandomUpgradeData")
	FScalableFloat ChanceToApplyPerContainer;

	UPROPERTY(EditAnywhere, Category="RandomUpgradeData")
	FScalableFloat Enabled;

	UPROPERTY(EditAnywhere, Category="RandomUpgradeData")
	TArray<FRandomUpgradeCalendarData> CalendarDrivenEnableState;

	UPROPERTY(EditAnywhere, Category="RandomUpgradeData")
	TArray<FMarkedActorDisplayInfo> MarkerDisplayInfoOverride;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("ForKismetOnly", "Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTimeOfDayLightsActorClassData)
class ABuildingContainer : public ABuildingTimeOfDayLights, public IFortMarkableActorInterface, public IFortSoundIndicatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void BounceContainer();

	UFUNCTION(BlueprintImplementableEvent, Category="Container")
	void DisableBacchusHighlight();

	UFUNCTION(BlueprintImplementableEvent, Category="Container")
	void EnableBacchusHighlight();

	UFUNCTION(BlueprintCallable, Category="Container")
	int32 GetLootTier();

	UFUNCTION(BlueprintImplementableEvent)
	AFortPlayerControllerAthena* GetOwningControllerForAnalytics() const;

	UFUNCTION(BlueprintCallable, Category="Container")
	AFortPlayerPawn* GetSearchingPawn();

	UFUNCTION(BlueprintImplementableEvent)
	void OnAuthorityRandomUpgradeApplied(const FName& UpgradeTierGroup);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginSearch();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoot();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLootRepeat();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLootReset();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRaiseTreasure();

	UFUNCTION()
	virtual void OnRep_bAlreadySearched();

	UFUNCTION()
	virtual void OnRep_ChosenRandomUpgrade();

	UFUNCTION()
	virtual void OnRep_LootTier();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchInterrupted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSearched();

	UFUNCTION(BlueprintCallable, Category="Container")
	void RaiseTreasure();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Container")
	void SetSearchLootTierGroup(FName InSearchLootTierGroup, bool bReRollForLootExistence = true, const bool bIgnorePotentialRandomUpgrades = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void StartAudiovisualIndicator(UAudioComponent* ForComponent, EFortSoundIndicatorTypes Type, float Interval);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void StopAudiovisualIndicator();

	UPROPERTY(BlueprintAssignable, Category="Container")
	FOnContainerSearchedStateChanged OnContainerSearchedStateChangedClient;

	UPROPERTY(BlueprintAssignable, Category="Container")
	FOnContainerRandomUpgradeApplied OnContainerRandomUpgradeApplied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundCue> SearchingSoundCueLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundCue> LootRepeatSoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundCue> OnDamageSoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundCue> OnDeathSoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Container")
	TObjectPtr<UStaticMesh> SearchedMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupData")
	FGameplayTagContainer AdditionalPickupTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupData")
	EFortPickupSpawnSource SpawnSourceOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Container")
	TArray<TObjectPtr<UMaterialInterface>> SearchedMaterialOverrides;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FVector2f NumItemsToDropRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	float SearchBounceRadiusOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float LootNoiseRange;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float LootNoiseLoudness_DEPRECATED;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LootTesting")
	TObjectPtr<UFortWorldItemDefinition> LootTestingData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FVector3f LootSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FVector3f InstancedLoot_TossDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	float InstancedLoot_TossSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	float InstancedLoot_TossConeHalfAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FVector3f LootSpawnLocation_Athena;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FRotator3f LootTossDirection_Athena;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	float LootTossSpeed_Athena;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	float LootTossConeHalfAngle_Athena;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Container")
	EFortRarity HighestRarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bUseLootProperties_Athena : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bAlwaysShowContainer : 1;

	UPROPERTY(EditAnywhere, Category="Container")
	uint8 bAlwaysMaintainLoot : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bDestroyContainerOnSearch : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bForceHidePickupMinimapIndicator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bForceSpawnLootOnDestruction : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bForceTossLootOnSpawn : 1;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_bAlreadySearched, Category="Container", meta=(DisplayName="Already Searched"))
	uint8 bAlreadySearched : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Container")
	uint8 bGivePickupsDirectlyToPlayer : 1;

	UPROPERTY(EditAnywhere, Category="Container")
	uint8 bDisableSpawnLoot : 1;

	UPROPERTY(EditAnywhere, Category="Container")
	uint8 bDoNotDropLootOnDestruction : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bSkipRollForDestruction : 1;

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Container", meta=(DisplayName="FinishSpawning"))
	void BP_FinishSpawning(const FName InSearchLootTierGroup, const FGameplayTagContainer& InGameplayTagContainer, const FTransform& InTransform);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Container", meta=(DisplayName="IsSearched"))
	bool BP_IsAlreadySearched();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Container", meta=(DisplayName="SetSearched"))
	void BP_SetAlreadySearched(bool bInAlreadySearched);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Container", meta=(DisplayName="SpawnLoot"))
	bool BP_SpawnLoot(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintPure, Category="Container")
	int32 GetChosenRandomUpgrade() const;

	UFUNCTION()
	void HandlePickedUpForAnalyticsEvent(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation);

	UPROPERTY(EditDefaultsOnly, Category="Container")
	TArray<FLootTierGroupTagOverride> LootTierGroupTagOverrideData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FName SearchLootTierGroup;

	UPROPERTY(SaveGame)
	FName ContainerLootTierKey;

	UPROPERTY(EditAnywhere, Category="Container")
	TArray<FRandomUpgradeData> PotentialRandomUpgrades;

	UPROPERTY(Transient)
	FChosenQuotaInfo SearchLootTierChosenQuotaInfo;

	UPROPERTY(ReplicatedUsing=OnRep_LootTier)
	int32 ReplicatedLootTier;

	UPROPERTY(ReplicatedUsing=OnRep_ChosenRandomUpgrade)
	int32 ChosenRandomUpgrade;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FVector3f MarkerPositionOffset;

	UPROPERTY(Transient)
	uint8 bSpawnedActor : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container", meta=(DisplayName="Buried Treasure"))
	uint8 bBuriedTreasure : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container", meta=(DisplayName="Has Raised Treasure"))
	uint8 bHasRaisedTreasure : 1;

	UPROPERTY(EditAnywhere, Category="Container")
	uint8 bStartAlreadySearched_Athena : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Container")
	uint8 bRegenerateLoot : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	uint8 bUseLocationForDrop : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Container", meta=(ClampMax="1.0", ClampMin="0.1", UIMax="1.0", UIMin="0.1"))
	float LootedWeaponsDurabilityModifier;

	UPROPERTY(Transient, ReplicatedUsing=BounceContainer)
	FFortSearchBounceData SearchBounceData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FCurveTableRowHandle SearchSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Container")
	FText SearchText;

	UPROPERTY(Transient)
	TObjectPtr<UCurveFloat> CurrentInteractBounceCurve;

	UPROPERTY(Transient)
	TObjectPtr<UCurveFloat> CurrentInteractBounceNormalCurve;

	UPROPERTY(Transient)
	float SavedReservedRandomValueResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Container", meta=(ClampMin="0", EditCondition="bRegenerateLoot", UIMin="0"))
	float TimeUntilLootRegenerates;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Sound Indicator", meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

};

