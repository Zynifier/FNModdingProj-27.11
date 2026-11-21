// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortItemQuantityPair.h"
#include "Player/FortPlayerController.h"
#include "FortPlayerControllerFrontEnd.generated.h"

class UAthenaMarkerComponent;
class UFortControllerComponent_FrontendQuests;
class UFortControllerComponent_MapDiscoverability;
class UFortControllerComponent_SeasonItem;

USTRUCT(BlueprintType)
struct FFortPhoenixLevelUpData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Phoenix Level Up")
	int32 Level;

	UPROPERTY(BlueprintReadOnly, Category="Phoenix Level Up")
	TArray<FFortItemInstanceQuantityPair> Rewards;

};

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerFrontEnd : public AFortPlayerController
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFrontEndMatchmakingComplete, bool, bSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFrontEndMatchmakingStarted);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchMakingDiscoveryRequested, FString, IslandMnemonic, const FName, PlayListName);

public:
	UFUNCTION(BlueprintCallable)
	void CloseEmotePicker();

	UFUNCTION(BlueprintCallable)
	void EmotePickerNextWheel();

	UFUNCTION(BlueprintCallable)
	void EmotePickerPrevWheel();

	UFUNCTION(BlueprintCallable)
	void EmotePickerSelect();

	UFUNCTION(BlueprintPure)
	bool HasPendingPhoenixLevelUpNotifications() const;

	UFUNCTION(BlueprintPure)
	bool IsInVoiceChat();

	UFUNCTION(BlueprintPure)
	bool IsVoiceChatPlayerMuted(const FUniqueNetIdRepl& UniqueNetId);

	UFUNCTION(BlueprintCallable)
	void OpenEmotePicker();

	UFUNCTION(BlueprintCallable)
	void RedeemSTWAccolades();

	UFUNCTION(BlueprintCallable, Exec)
	void RunFacialAnimationTest(const FString& WaveFileName, int32 SampleRate);

	UFUNCTION(BlueprintCallable, Exec)
	void StartWriteToAudioFile();

	UFUNCTION(BlueprintCallable, Exec)
	void StopFacialAnimationTest();

	UFUNCTION(BlueprintCallable, Exec)
	void StopWriteToAudioFile();

	UPROPERTY(BlueprintAssignable)
	FOnFrontEndMatchmakingStarted FrontEndMatchmakingStarted;

	UPROPERTY(BlueprintAssignable)
	FOnFrontEndMatchmakingComplete FrontEndMatchmakingComplete;

	UPROPERTY(Transient)
	bool bUnlockAllZones;

protected:
	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerFrontEnd", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_MapDiscoverability> DiscoverabilityComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerFrontEnd", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SeasonItem> SeasonItemComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerControllerFrontEnd", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_FrontendQuests> FrontendQuestsComponent;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMarkerComponent> MarkerComponent;

	UPROPERTY(Config)
	bool bEnableSTWAccoladeRedeem;

};

