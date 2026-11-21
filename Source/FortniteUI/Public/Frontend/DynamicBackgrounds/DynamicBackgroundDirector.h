// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortDynamicBackgroundKey.h"
#include "Frontend/Lobby/FrontendLobbyData.h"
#include "DynamicBackgroundDirector.generated.h"

class UTexture2D;
class UTexture;
enum class EBackgroundSource : uint8;

UENUM()
enum class EBackgroundSource : uint8
{
	CMS = 0,
	LobbyData = 1,
	URL = 2,
};

UCLASS()
class FORTNITEUI_API ADynamicBackgroundDirector : public AActor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDonutSequenceInitiated);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDonutSequencePlayDonutDrop);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDonutSetupLateStore);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnteredItemShop);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnteredStore);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnvironmentBackgroundTextureChangedDynamic, UTexture*, BackgroundImage);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnvironmentChangedDynamic, FString, PresetEnvironmentName);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyDataChanged, FFrontendLobbyData, LobbyData);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRequestDelegate);

public:
	UFUNCTION(BlueprintPure)
	EBackgroundSource GetBackgroundSource() const;

	UFUNCTION(BlueprintCallable)
	bool GetHasDonutShopSequenceBeenSeen();

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UTexture> GetLoadedTexture();

	UFUNCTION(BlueprintCallable)
	void MarkDonutSequenceSeen();

	UFUNCTION(BlueprintCallable)
	void OnDonutSequenceInitiated();

	UFUNCTION(BlueprintCallable)
	void RequestDonutUIPlayAnim();

	UFUNCTION(BlueprintCallable)
	void ResetDonutShopSeen();

	UFUNCTION(BlueprintCallable)
	void SetIsInDonutSequence(bool bIsInSequence);

	UFUNCTION(BlueprintCallable)
	void TryForceSetupDonutStore();

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Donut Sequence Initiated"))
	FOnDonutSequenceInitiated BP_OnDonutSequenceInitiated;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Entered Item Shop"))
	FOnEnteredItemShop BP_OnEnteredItemShop;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Entered Store"))
	FOnEnteredStore BP_OnEnteredStore;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Environment Changed"))
	FOnDonutSequencePlayDonutDrop BP_OnDonutSequencePlayDonutDrop;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Environment Changed", ScriptName="OnEnvironmentChanged"))
	FOnEnvironmentChangedDynamic BP_OnEnvironmentChanged;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Background Texture Changed", ScriptName="OnBackgroundTextureChanged"))
	FOnEnvironmentBackgroundTextureChangedDynamic BP_OnEnvironmentBackgroundTextureChanged;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Lobby Data Changed", ScriptName="OnLobbyDataChanged"))
	FOnLobbyDataChanged BP_OnLobbyDataChanged;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Request Show Background", ScriptName="OnRequestShowBackground"))
	FRequestDelegate BP_OnRequestShowBackground;

	UPROPERTY(BlueprintAssignable, Category="DynamicBackgroundDirector", meta=(DisplayName="On Request Hide Background", ScriptName="OnRequestHideBackground"))
	FRequestDelegate BP_OnRequestHideBackground;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DynamicBackgroundDirector")
	EDynamicBackgroudKey DynamicBackgroundKey;

private:
	UPROPERTY(Transient)
	TMap<FString, TObjectPtr<UTexture2D>> TextureCache;

};

