// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "Components/FortPawnComponent_CustomDepth.h"
#include "FortCombatTypes.h"
#include "FortTeamEnum.h"
#include "FortControllerComponent_IndicatedActorManagement.generated.h"

class AActor;
class AFortPlayerStateAthena;
class APawn;
class UParticleSystem;
class USoundBase;

UENUM(BlueprintType)
enum class EIndicatorStateImage : uint8
{
	/** State Icons */
	FIRST_FRIENDLY_STATE = 0 UMETA(Hidden),
	Default = 0,
	/* Instead of using default for teammates and squadmates, we should make their own entry. */
	InCombat = 1,
	/* This doesn't seem to work, need to figure out why. */
	DBNO = 2,
	BeingRevived = 3,
	Dead = 4,
	LAST_FRIENDLY_STATE = 4 UMETA(Hidden),
	/** Chat Icons */
	FIRST_CHAT_MESSAGE = 5 UMETA(Hidden),
	NeedAmmoHeavy = 5,
	NeedAmmoLight = 6,
	NeedAmmoMedium = 7,
	NeedAmmoShells = 8,
	NeedAmmoRocket = 9,
	ChatBubble = 10,
	EnemySpotted = 11,
	NeedBandages = 12,
	NeedMaterials = 13,
	NeedShields = 14,
	NeedWeapon = 15,
	LAST_CHAT_MESSAGE = 15 UMETA(Hidden),
	FIRST_MATE_STATE = 16 UMETA(Hidden),
	Squadmate = 16,
	Teammate = 17,
	LAST_MATE_STATE = 17 UMETA(Hidden),
	FIRST_ENEMY_STATE = 18 UMETA(Hidden),
	Enemy = 18,
	LAST_ENEMY_STATE = 18 UMETA(Hidden),
	FIRST_NPC_STATE = 19 UMETA(Hidden),
	FriendlyNPC = 19,
	EnemyNPC = 20,
	EliteFriendlyNPC = 21,
	EliteEnemyNPC = 22,
	LAST_NPC_STATE = 22 UMETA(Hidden),
	FIRST_WORLDITEM_STATE = 23 UMETA(Hidden),
	Interactable = 23,
	InteractableLarge = 24,
	GameplayItem = 25,
	TreasureChest = 26,
	LAST_WORLDITEM_STATE = 26 UMETA(Hidden),
	FIRST_HARDCORE_STATE = 27 UMETA(Hidden),
	HardCoreBeacon = 27,
	LAST_HARDCORE_STATE = 27 UMETA(Hidden),
	LAST_STATE = 27 UMETA(Hidden),
	None = 28,
	/** Maximum */
	MAX = 29,
};

UENUM(BlueprintType)
enum class EShareActorWith : uint8
{
	None = 0,
	SquadOnTeam = 1,
	AllTeam = 2,
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EShareActorWithMask : uint8
{
	None = 0 UMETA(Hidden),
	SquadOnTeam = 1,
	AllTeam = 2,
	Target = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnIndicatedActorAdded, AActor*, IndicatedActor);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnIndicatedActorRemoved, AActor*, IndicatedActor);

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FIndicatedActorParticleSystemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="IndicatedActorParticleSystemData")
	TObjectPtr<UParticleSystem> ParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category="IndicatedActorParticleSystemData")
	FName ParticleSystemActorParamName;

	UPROPERTY(EditDefaultsOnly, Category="IndicatedActorParticleSystemData")
	FVector ParticleSystemOffset;

	UPROPERTY(EditDefaultsOnly, Category="IndicatedActorParticleSystemData")
	FVector ParticleSystemDBNOOffset;

	UPROPERTY(EditDefaultsOnly, Category="IndicatedActorParticleSystemData")
	FName ParticleSystemVectorParamName;

};

USTRUCT(BlueprintType)
struct FIndicatedActorScaleAndOpacityData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float SmallSizeDistance;

	UPROPERTY()
	float LargestSizeDistance;

	UPROPERTY()
	float SmallScale;

	UPROPERTY()
	float LargestScale;

	UPROPERTY()
	float FarAwayScale;

	UPROPERTY()
	float FarAwayOpacity;

	UPROPERTY()
	float MaxScaleAndFadePercent;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FIndicatedActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	FString GroupIdentifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	float StepTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	FVector IndicatorOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	FVector IndicatorDBNOOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	EShareActorWith ShareActorWith;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EShareActorWithMask"))
	uint8 ShareActorWithMask;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="IndicatedActorData")
	uint8 DisplayTeamOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	FIndicatedActorScaleAndOpacityData ScaleAndOpacityData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	FIndicatedActorParticleSystemData ParticleSystemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	EIndicatorStateImage StateImageOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	uint8 bClampToScreen : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	uint8 bHideStateImage : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorData")
	uint8 bOnlyDisplayWhenStencilingIsDisabled : 1;

	UPROPERTY(BlueprintReadWrite, Category="IndicatedActorData")
	FOnIndicatedActorAdded OnActorAdded;

	UPROPERTY(BlueprintReadWrite, Category="IndicatedActorData")
	FOnIndicatedActorRemoved OnActorRemoved;

	UPROPERTY(BlueprintReadWrite, Category="IndicatedActorData")
	FGameplayTagContainer EventTags;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FStenciledActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	FString GroupIdentifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	float StepTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="StenciledActorData")
	EShareActorWith ShareActorWith;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EShareActorWithMask"))
	uint8 ShareActorWithMask;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="StenciledActorData")
	uint8 DisplayTeamOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	FIndicatedActorParticleSystemData ParticleSystemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	FName FriendlyStencilName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StenciledActorData")
	FName EnemyStencilName;

	UPROPERTY()
	uint8 FriendlyStencilIndex;

	UPROPERTY()
	uint8 EnemyStencilIndex;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FIndicatedActorDataWithFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	FGameplayTagContainer IndicatedActorTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	FGameplayTagQuery IndicatedActorTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	TSoftClassPtr<AActor> ActorClassFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	TArray<TEnumAsByte<EFortTeamAffiliation::Type>> WithAffiliation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	FIndicatedActorData IndicatedData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter")
	FStenciledActorData StenciledData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter", meta=(ClampMin="0.0"))
	float OverlapRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IndicatedActorDataWithFilter", meta=(ClampMin="0.0"))
	float OverlapHalfHeight;

};

USTRUCT()
struct FIndicatedActorInfoEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<AActor> Actor;

	UPROPERTY()
	float StartTime;

	UPROPERTY()
	float EndTime;

	UPROPERTY()
	FIndicatedActorData Data;

	UPROPERTY()
	uint8 bReplaceExistingWhenAdded : 1;

	UPROPERTY()
	uint8 bRefreshExistingWhenAdded : 1;

	UPROPERTY(Transient, NotReplicated)
	uint8 bWasActorValidDuringPreviousUpdate : 1;

};

USTRUCT()
struct FIndicatedActorInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FIndicatedActorInfoEntry> Entries;

};

USTRUCT()
struct FStenciledActorInfoEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<AActor> Actor;

	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> MarkedBy;

	UPROPERTY()
	float StartTime;

	UPROPERTY()
	float EndTime;

	UPROPERTY()
	FStenciledActorData Data;

	UPROPERTY()
	uint8 bReplaceExistingWhenAdded : 1;

	UPROPERTY()
	uint8 bRefreshExistingWhenAdded : 1;

	UPROPERTY(Transient, NotReplicated)
	uint8 bWasActorValidDuringPreviousUpdate : 1;

	UPROPERTY(Transient, NotReplicated)
	FCustomHighlightingHandle CustomHighlightingHandle;

};

USTRUCT()
struct FStenciledActorInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FStenciledActorInfoEntry> Entries;

};

UCLASS(Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_IndicatedActorManagement : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddActorsToIndicatedList(TArray<AActor*>& IndicatedActors, FIndicatedActorData Data, const bool bAddAsUnique, const bool bAllowOwningPlayer, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry);

	UFUNCTION()
	void AddActorsToStenciledList(TArray<AActor*>& StenciledActors, FStenciledActorData Data, const bool bAddAsUnique, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry);

	UFUNCTION()
	void RemoveActorFromIndicatedList(AActor* IndicatedActor, const bool bIncludeSquad);

	UFUNCTION()
	void RemoveActorFromStenciledList(AActor* StenciledActor, const bool bIncludeSquad);

	UFUNCTION()
	void RemoveGroupFromIndicatedList(const FString& GroupIdentifier, const bool bIncludeSquad);

	UFUNCTION()
	void RemoveGroupFromStenciledList(const FString& GroupIdentifier, const bool bIncludeSquad);

private:
	UFUNCTION()
	void OnHardCoreBeaconPlayerPawnDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION()
	void OnHardCoreBeaconPlayerPawnPossessed(APawn* PossessedPawn);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerComponent_IndicatedActorManagement", meta=(AllowPrivateAccess="true"))
	FScalableFloat UpdateIndicatedActors;

	UPROPERTY(Replicated)
	FIndicatedActorInfoArray IndicatedActorList;

	UPROPERTY()
	TArray<FIndicatedActorInfoEntry> DeferredIndicatedActorList;

	UPROPERTY(Replicated)
	FStenciledActorInfoArray StenciledActorList;

	UPROPERTY()
	TArray<FStenciledActorInfoEntry> DeferredStenciledActorList;

};

