// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Customization/CustomPlayerDataSource.h"
#include "FGF_PlayerState.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortGender.h"
#include "FortTeamActorInterface.h"
#include "FortTypes.h"
#include "Items/FortPersistentTypes.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Pawns/FortPawnDamageData.h"
#include "FortPlayerState.generated.h"

class AActor;
class AFortPickup;
class AFortPlayerPawn;
class AFortTeamInfo;
class AFortTeamPrivateInfo;
class UAthenaCharmItemDefinition;
class UCustomCharacterPart;
class UCustomColorSwatch;
class UCustomPlayerComponent;
class UFortAbilitySystemComponent;
class UFortAdvancedMovementSet;
class UFortCharacterAttrSet;
class UFortConstructionSet;
class UFortControlResistanceSet;
class UFortDamageSet;
class UFortHeroType;
class UFortHomebaseSet;
class UFortMovementSet;
class UFortPlayerAttrSet;
class UFortPlayerStateComponent_Habanero;
class UFortPlayerStateComponent_Quests;
class UFortRegenHealthSet;
class UFortWeaponAttrSet;

UENUM()
enum class ETrustedPlatformType : uint8
{
	Unknown = 0,
	Untrusted = 1,
	PS4 = 2,
	PS5 = 3,
	XboxOne = 4,
	Switch = 5,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStatePawnDied, const FPawnDamageData&, PawnDamageInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleMutatorDynamicMulticastDelegate);

USTRUCT()
struct FCustomCharacterData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 WasPartReplicatedFlags;

	UPROPERTY()
	int32 RequiredVariantPartFlags;

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomCharacterPart> Parts[7];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomCharmType"))
	TObjectPtr<UAthenaCharmItemDefinition> Charms[4];

	UPROPERTY()
	TArray<TObjectPtr<UCustomCharacterPart>> VariantRequiredCharacterParts;

private:
	UPROPERTY(Transient, NotReplicated)
	bool bReplicationFailed;

};

USTRUCT(BlueprintType)
struct FFortPlayerAttributeSets
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortRegenHealthSet> HealthSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortControlResistanceSet> ControlResistanceSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortMovementSet> MovementSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortAdvancedMovementSet> AdvancedMovementSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortConstructionSet> ConstructionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortPlayerAttrSet> PlayerAttrSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortCharacterAttrSet> CharacterAttrSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortWeaponAttrSet> WeaponAttrSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortHomebaseSet> HomebaseSet;

};

USTRUCT(BlueprintType)
struct FPlayerBannerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerBannerInfo")
	FString IconId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerBannerInfo")
	FString ColorId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerBannerInfo")
	int32 Level;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayerState : public AFGF_PlayerState, public IFortTeamActorInterface, public IFortAbilitySystemInterface, public IVisualLoggerDebugSnapshotInterface, public ICustomPlayerDataSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="PlayerState")
	static bool AreUniqueIDsIdentical(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void ChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn = nullptr);

	UFUNCTION(BlueprintPure, Category="PlayerState")
	AFortPlayerPawn* GetCurrentPawn() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	const UFortHeroType* GetHeroType() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	FString GetPlatform() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	FUniqueNetIdRepl GetPlatformUniqueNetId() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	FName GetPlayerOSSName() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	AFortPlayerPawn* GetPlayerPawnOrVehicleDriver() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	virtual FUniqueNetIdRepl GetPlayerUniqueNetID() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	FUniqueNetIdRepl GetUniqueID() const;

	UFUNCTION(BlueprintPure)
	bool HasLocalPlayerController() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	bool HasStartedPlaying() const;

	UFUNCTION(BlueprintPure, Category="PlayerState")
	bool IsSimulatingDamage() const;

	UFUNCTION()
	void OnInstigatorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void OnRep_BannerInfo();

	UFUNCTION()
	virtual void OnRep_CharacterData();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PlayerState")
	void SetIsSimulatingDamage(const bool bSimulateDamage);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Attributes")
	FFortPlayerAttributeSets AttributeSets;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AbilitySystem", meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="FortPlayerState")
	FSimpleMutatorDynamicMulticastDelegate OnMutatorListUpdatedDelegate;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UFUNCTION()
	void OnRep_AccessoryColorSwatches();

	UFUNCTION()
	void OnRep_bHasStartedPlaying();

	UFUNCTION()
	virtual void OnRep_bIsSimulatingDamage();

	UFUNCTION()
	void OnRep_CharacterBodyType();

	UFUNCTION()
	void OnRep_CharacterColorSwatches();

	UFUNCTION()
	void OnRep_CharacterGender();

	UFUNCTION()
	void OnRep_CurrentCharXP();

	UFUNCTION()
	void OnRep_HeroID();

	UFUNCTION()
	virtual void OnRep_HeroType();

	UFUNCTION()
	virtual void OnRep_HomeActor(AActor* OldHomeActor);

	UFUNCTION()
	virtual void OnRep_PartyOwner();

	UFUNCTION()
	virtual void OnRep_Platform();

	UFUNCTION()
	virtual void OnRep_PlatformUniqueNetId();

	UFUNCTION()
	virtual void OnRep_PlayerTeam();

	UFUNCTION()
	virtual void OnRep_PlayerTeamPrivate();

	UFUNCTION()
	void OnRep_ScoreStatChanged();

	UFUNCTION()
	void OnRep_SessionOwner();

	UFUNCTION()
	virtual void UpdateScoreStatChanged();

	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomGender::Type> LocalCharacterGender;

	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomBodyType::Type> LocalCharacterBodyType;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomCharacterPart> LocalCharacterParts[7];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomCharmType"))
	TObjectPtr<UAthenaCharmItemDefinition> LocalCharacterCharms[4];

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomCharacterPart>> LocalVariantPartsToLoad;

	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> ActiveVariantOverrides;

	UPROPERTY(Transient)
	TArray<FFortAppliedSwapItemAndVariantData> ActiveCosmeticItemSwaps;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.ECharacterColorSwatchType"))
	TObjectPtr<UCustomColorSwatch> LocalCharacterColorSwatches[2];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomColorSwatch> LocalCharacterPartColorSwatches[7];

	UPROPERTY()
	bool bSkipReplicatedStats;

	UPROPERTY()
	FName PlayerOSSName;

	UPROPERTY()
	ETrustedPlatformType TrustedPlatformType;

	UPROPERTY(Transient)
	bool bInvitedToConsoleSession;

	UPROPERTY(Transient)
	bool bInitializedPlayerCustomizationOptionsFromClientSettings;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerStatePawnDied OnPawnDiedDelegate;

private:
	UFUNCTION()
	void OnRep_InGhostMode();

	UPROPERTY(Transient, Replicated)
	uint8 bIsWorldDataOwner : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SessionOwner)
	uint8 bIsGameSessionOwner : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsGameSessionAdmin : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsReadyToContinue : 1;

	UPROPERTY(Replicated)
	uint8 bHasFinishedLoading : 1;

	UPROPERTY(ReplicatedUsing=OnRep_bHasStartedPlaying)
	uint8 bHasStartedPlaying : 1;

	UPROPERTY(Replicated)
	uint8 bRepFlag1 : 1;

	UPROPERTY(Transient, Replicated)
	EFortPlayerRole PlayerRole;

	UPROPERTY(Replicated)
	int16 WorldPlayerId;

	UPROPERTY(ReplicatedUsing=OnRep_PartyOwner)
	FUniqueNetIdRepl PartyOwnerUniqueId;

	UPROPERTY(ReplicatedUsing=OnRep_HeroID)
	FString HeroId;

	UPROPERTY(ReplicatedUsing=OnRep_HeroType)
	TObjectPtr<UFortHeroType> HeroType;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentCharXP)
	int32 CurrentCharXP;

	UPROPERTY(Replicated)
	TWeakObjectPtr<AFortPickup> MyBackpackPickup;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ScoreStatChanged)
	int32 InitialExperienceLevel;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ScoreStatChanged)
	int32 InitialExperienceAmount;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ScoreStatChanged)
	TArray<FFortExperienceDelta> ExperienceDeltas;

	UPROPERTY(ReplicatedUsing=OnRep_Platform)
	FString Platform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_BannerInfo, Category="FortPlayerState", meta=(AllowPrivateAccess="TRUE"))
	FPlayerBannerInfo Banner;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsSimulatingDamage)
	bool bIsSimulatingDamage;

	UPROPERTY(Replicated)
	FString EOSProductUserId;

	UPROPERTY(ReplicatedUsing=OnRep_CharacterGender)
	TEnumAsByte<EFortCustomGender::Type> CharacterGender;

	UPROPERTY(ReplicatedUsing=OnRep_CharacterBodyType)
	TEnumAsByte<EFortCustomBodyType::Type> CharacterBodyType;

	UPROPERTY(ReplicatedUsing=OnRep_CharacterData)
	FCustomCharacterData CharacterData;

	UPROPERTY(ReplicatedUsing=OnRep_CharacterColorSwatches, meta=(ArraySizeEnum="/Script/FortniteGame.ECharacterColorSwatchType"))
	TObjectPtr<UCustomColorSwatch> CharacterColorSwatches[2];

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCustomPlayerComponent> CustomPRIComponent;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_AccessoryColorSwatches, Category="CharacterParts", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomColorSwatch> CharacterPartColorSwatches[7];

	UPROPERTY(ReplicatedUsing=OnRep_PlayerTeam)
	TWeakObjectPtr<AFortTeamInfo> PlayerTeam;

	UPROPERTY(ReplicatedUsing=OnRep_PlayerTeamPrivate)
	TWeakObjectPtr<AFortTeamPrivateInfo> PlayerTeamPrivate;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ScoreStatChanged, meta=(ArraySizeEnum="/Script/FortniteGame.EFortReplicatedStat"))
	FReplicatedStatValues ReplicatedStats_Campaign[35];

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ScoreStatChanged, meta=(ArraySizeEnum="/Script/FortniteGame.EFortReplicatedStat"))
	FReplicatedStatValues ReplicatedStats_Zone[35];

	UPROPERTY(Transient, Replicated)
	bool bAreZoneStatsFinalized;

	UPROPERTY(Replicated)
	EReadyCheckState ReadyCheckState;

	UPROPERTY(ReplicatedUsing=OnRep_HomeActor)
	TObjectPtr<AActor> HomeActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortPlayerStateComponent_Quests* QuestsComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	UFortPlayerStateComponent_Habanero* HabaneroComponent;

	UPROPERTY(ReplicatedUsing=OnRep_PlatformUniqueNetId)
	FUniqueNetIdRepl PlatformUniqueNetId;

	UPROPERTY(Transient)
	FVector PawnDeathLocation;

	UPROPERTY(Transient)
	int32 CachedPreviousWorldPlayerId;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_InGhostMode)
	bool bInGhostMode;

};

