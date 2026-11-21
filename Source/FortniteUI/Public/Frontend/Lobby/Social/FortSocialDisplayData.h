// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "UObject/SoftObjectPath.h"
#include "FortSocialDisplayData.generated.h"

class UDataAsset;
class UFortSocialBanModal;
class UFortVoiceChannelSpeakerWidget;
class UFortVoiceSpeakerContainerWidget;
class UImage;
class UMaterialInstance;
class UTexture2D;

USTRUCT(BlueprintType)
struct FPlatformPrefixIcon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PlatformPrefixIcon")
	FString Platform;

	UPROPERTY(EditDefaultsOnly, Category="PlatformPrefixIcon")
	TObjectPtr<UTexture2D> PrefixIcon;

};

USTRUCT(BlueprintType)
struct FPlatformPrefixIconList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PlatformPrefixIconList")
	TArray<FPlatformPrefixIcon> PlatformPrefixIcons;

};

UCLASS(Config=Game)
class UFortSocialDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LoadingScreenSpeakerWidgetData")
	TSoftClassPtr<UFortVoiceSpeakerContainerWidget> LoadingActiveChannelSpeakContainerClass;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreenSpeakerWidgetData")
	TSoftClassPtr<UFortVoiceChannelSpeakerWidget> LoadingOverrideSpeakerClass;

	UPROPERTY(EditDefaultsOnly, Category="AudioModeration")
	TSoftClassPtr<UDataAsset> LoadingVoiceRecordingPluginAssetClass;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor OnlineIndicatorOnline;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor OnlineIndicatorAway;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor OnlineIndicatorOffline;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor OnlineIndicatorBlocked;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor UserNameOnline;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor UserNameOfflineAway;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor UserNameBlocked;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor RichPresenceOnline;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor RichPresenceOfflineAway;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor RichPresenceBlocked;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor FocusHighlightOnline;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor FocusHighlightOfflineAway;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor PortraitBackgroundColorNormal;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor PortraitBackgroundColorAttendingEvent;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor PortraitEmptyFillColorNormal;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor PortraitEmptyFillColorAttendingEvent;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor PortraitEmptyHighlightColorNormal;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor PortraitEmptyHighlightColorAttendingEvent;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor StatusIndicatorBackgroundOn;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	FLinearColor StatusIndicatorBackgroundOff;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	TObjectPtr<UMaterialInstance> BackgroundOnline;

	UPROPERTY(EditDefaultsOnly, Category="PresenceProperties")
	TObjectPtr<UMaterialInstance> BackgroundOfflineAway;

	UPROPERTY(EditDefaultsOnly, Category="Sidebar")
	TObjectPtr<UMaterialInstance> BackgroundSidebarCell;

	UPROPERTY(EditDefaultsOnly, Category="Sidekick")
	TMap<FString, FSoftObjectPath> SidekickReactionPathMap;

private:
	UPROPERTY(EditDefaultsOnly, Category="Crossplay")
	TMap<FString, FPlatformPrefixIconList> PlatformPrefixIconMap;

	UPROPERTY(EditDefaultsOnly, Category="Crossplay")
	TObjectPtr<UTexture2D> GenericPlatformIcon;

	UPROPERTY(EditDefaultsOnly, Category="SocialBanning")
	TSubclassOf<UFortSocialBanModal> SocialBanModalClass;

};

UCLASS()
class FORTNITEUI_API UFortSocialDisplayLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SocialDisplayLibrary")
	static void SetPlatformPrefixIcon(UImage* Image, const FString& OtherPlayerPlatform);

};

