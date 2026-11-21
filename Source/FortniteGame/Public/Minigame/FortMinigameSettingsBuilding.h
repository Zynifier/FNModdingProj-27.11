// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "Building/FortVolumeAccessorInterface.h"
#include "Building/SpatialGameplay/SpatialGameplayContextEvent.h"
#include "Creative/FortCreativeEventSystemType.h"
#include "Creative/FortCreativeTeamOption.h"
#include "Creative/FortCreativeTypes.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortUserOptionSettingsInterface.h"
#include "FortUserOptionValues.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "LevelSaveSpawnableInterface.h"
#include "Minigame/FortMinigameTypes.h"
#include "FortMinigameSettingsBuilding.generated.h"

class AActor;
class AFortMinigame;
class AFortVolume;
class UDataTable;
class UFortCreativeRichTextStyleSets;
class UFortCreativeVolumeLinkComponent;
enum class ECreativePublishedIslandCodeDisplay : uint8;

UENUM(BlueprintType)
enum class ECreativeUITeamColors : uint8
{
	Relationship = 0,
	TeamColor = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameDescriptionDataChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameNameChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVolumeMachineSetDelegate);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), ClassGroup=("Minigame"), SparseClassDataType=UserOptionDefinitionContainer)
class AFortMinigameSettingsBuilding : public AInfo, public ILevelSaveSpawnable, public IFortVolumeAccessor, public IFortDataRegistryResolverScopeInterface, public IFortUserOptionSettings, public IUserOptionValuesInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Minigame")
	void AbandonMinigame_BP();

	UFUNCTION(BlueprintPure, Category="Game Data")
	TArray<FText> GetGameDescription();

	UFUNCTION(BlueprintPure, Category="Game Data")
	FText GetGameName();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	int32 GetMaxHUDTrackers() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	AFortMinigame* GetMinigame() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	const FMinigamePostGameSettings& GetPostGameSettings() const;

	UFUNCTION(BlueprintPure)
	UDataTable* GetSelectedTextStyleSet() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, meta=(CallInEditor="true"))
	int32 GetTeamSetting() const;

	UFUNCTION(BlueprintPure)
	bool HasUpgradedDevices() const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void OverridePostGameSettings(const FMinigamePostGameSettings& NewSettings);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Game Data")
	void SetGameDescription(const FText& GameName, const TArray<FText>& GameDescriptionText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Minigame")
	void StartMinigame_BP();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortMinigameSettingsBuilding", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeVolumeLinkComponent> CreativeLinkComponent;

	UPROPERTY(VisibleInstanceOnly, SaveGame, ReplicatedUsing=OnRep_GameDescriptionData, Category="Game Data")
	TArray<FText> GameDescriptionData;

	UPROPERTY(VisibleInstanceOnly, SaveGame, ReplicatedUsing=OnRep_GameNameData, Category="Game Data")
	FText GameNameData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Legacy")
	bool bShowIslandCodeWatermark;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="UserOptions")
	ECreativeUITeamColors UITeamColors;

	UPROPERTY(BlueprintAssignable, Category="Game Data")
	FGameDescriptionDataChangedDelegate OnGameDescriptionDataChanged;

	UPROPERTY(BlueprintAssignable, Category="Game Data")
	FGameNameChangedDelegate OnGameNameDataChanged;

	UPROPERTY(BlueprintAssignable, Category="Game Data")
	FVolumeMachineSetDelegate OnVolumeMachineSet;

	UPROPERTY(EditAnywhere, Category="Game Data")
	bool bAllowOutOfBounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="UserOptions")
	bool bUseCustomMatchmakingSettings;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	int32 Matchmaking_MaxPlayersPerSession;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	int32 Matchmaking_MaxTeamCount;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	int32 Matchmaking_MaxTeamSize;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	int32 Matchmaking_MaxSocialPartySize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="UserOptions|GameData")
	bool bShowResourceFeedOnEliminations;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	ECreativePublishedIslandCodeDisplay GetPublishedIslandCodeDisplay() const;

	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Handle User Options Changed"))
	void K2_HandleUserOptionsChanged(const TArray<FName>& ChangedPropertyNames);

	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Handle User Options Loaded"))
	void K2_HandleUserOptionsLoaded();

	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Migrate Legacy User Options"))
	void K2_MigrateLegacyUserOptions();

	UFUNCTION()
	void OnLinkedVolumeSet(AFortVolume* PreviousVolume, AFortVolume* NewVolume);

	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnRep_GameDescriptionData();

	UFUNCTION()
	void OnRep_GameNameData();

	UFUNCTION()
	void OnSaveComponentFinishSpawning(FEventMessageTag Channel, const FSpatialGameplayInterfaceContext& Context);

	UFUNCTION(BlueprintCallable)
	void UpdateMatchmakingSetings();

	UFUNCTION()
	void UpdateMatchmakingSettings();

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions|GameData")
	bool bKeepPlayerBuiltStructuresBetweenRounds;

	UPROPERTY(SaveGame)
	bool bWasUsingDirectEventBindingWhenSaved;

	UPROPERTY(EditDefaultsOnly, Category="Game Data")
	bool bExposeLinkedVolumePropertiesForEditing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMinigameSettingsBuilding")
	FCreativeIslandMatchmakingSettings MatchmakingSettings;

	UPROPERTY(VisibleInstanceOnly, SaveGame, Replicated, Category="FortMinigameSettingsBuilding")
	EFortCreativeEventSystemType EventSystem;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions", meta=(ValidEnumValues="KeepFull,Off"))
	EMMSRulePreset MatchmakingType;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	bool bOverrideRespectParties;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	EMMSPrivacy MatchmakingPrivacy;

	UPROPERTY(Transient)
	bool bPrefersRespectingPartiesFromMMS;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions", meta=(ClampMax="100", ClampMin="1"))
	int32 MaxPlayers;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	EMMSPlayersPerTeamPreset TeamSize;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	EMMSTeamFillOption TeamFillOption;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="UserOptions", meta=(TeamTypesToShow="Spectate,Spawn,SpawnOnNextRound,TeamIndex"))
	FCreativeTeamOption JoinInProgress;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions")
	bool bForceStartAtMaxPlayers;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions", meta=(ClampMax="30", ClampMin="0"))
	int32 ForceStartDelay;

	UPROPERTY(EditAnywhere, Category="Legacy")
	TObjectPtr<UFortCreativeRichTextStyleSets> RichTextStylesList;

	UPROPERTY(EditAnywhere, SaveGame, Category="Legacy", meta=(ClampMin="0"))
	int32 TextStyleIndex;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions", meta=(RequiredAssetDataTags="RowStructure=/Script/UMG.RichTextStyleRow"))
	TObjectPtr<UDataTable> TextStyle;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry|Building")
	FScalableFloat PlayerBuiltWoodStructureHealthMultiplierSetting;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry|Building")
	FScalableFloat PlayerBuiltStoneStructureHealthMultiplierSetting;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry|Building")
	FScalableFloat PlayerBuiltMetalStructureHealthMultiplierSetting;

private:
	UFUNCTION()
	void CheckPublishedIslandCodeDisplayChanged();

	UFUNCTION()
	void OnRep_SettingsVolume();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SettingsVolume)
	TObjectPtr<AActor> SettingsVolume;

	UPROPERTY(VisibleAnywhere, Category="FortMinigameSettingsBuilding")
	FGuid SavedActorGuid;

	UPROPERTY(Transient, Replicated)
	FMinigamePostGameSettings PostGameSettingsOverride;

	UPROPERTY(EditDefaultsOnly, Category="FortMinigameSettingsBuilding")
	bool bHasUpgradedDevices;

};

