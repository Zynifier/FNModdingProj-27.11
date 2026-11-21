// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "FortUIStateWidget_ForcedIntro.generated.h"

class UAthenaLoadingScreenItemDefinition;
class UCommonTextBlock;
class UUserWidget;
enum class EForcedIntroTextDisplayState : uint8;

UENUM(BlueprintType)
enum class EForcedIntroTextDisplayState : uint8
{
	Initialized = 0,
	WaitingForPlaylistPlugin = 1,
	WaitingForMatchmakingStartTime = 2,
	InitialDelay = 3,
	Matchmaking = 4,
	Success = 5,
	Failure = 6,
};

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortUIStateWidget_ForcedIntro : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	TSoftClassPtr<UUserWidget> GetPlaylistLoadingScreenWidget() const;

	UFUNCTION(BlueprintNativeEvent)
	void OnNewForcedIntroTextDisplayState(EForcedIntroTextDisplayState NewState);

	UFUNCTION(BlueprintCallable, Exec)
	void StartMatch();

	UPROPERTY(EditDefaultsOnly, Config, Category="Playlist")
	FString PlaylistPluginName;

	UPROPERTY(EditDefaultsOnly, Config, Category="Playlist")
	FName PlaylistName;

	UPROPERTY(Config)
	FDateTime MatchmakingStartTime;

	UPROPERTY(Config)
	float MatchmakingStartTimeRandomness;

	UPROPERTY(Config)
	bool bUseMCPTime;

	UPROPERTY(Config)
	float MaxWaitTimeForMeshConfig;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	float InitialDelayBeforeMM;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	float MMTimeoutTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	int32 MaxNumOfMMAttempts;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	float TimeBetweenMMAttempts;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	float TimeBetweenMMAttemptsMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	bool bLocalOnlyOnFail;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	bool bSetToDefaulPlaylistOnDeactivated;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking")
	bool bSetLocalHasSeenForcedIntroOnDeactivated;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortUIStateWidget_ForcedIntro")
	TObjectPtr<UAthenaLoadingScreenItemDefinition> LoadingScreenDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortUIStateWidget_ForcedIntro", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ForcedIntroState;

};

