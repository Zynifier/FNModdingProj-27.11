// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateColor.h"
#include "FortHUDElementWidget.h"
#include "AthenaPlayerInfoBase.generated.h"

class AFortPlayerStateAthena;
class UAthenaLevelEffects;
class UAthenaTeamMemberDBNOState;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UContentWidget;
class UFortSocialAvatarIcon;
class UFortVoiceChatStatusIconProxyAnim;
class UImage;
class UOverlay;
class UTexture2D;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

USTRUCT(BlueprintType)
struct FFortResurrectionUIData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortResurrectionUIData")
	bool bResurrectionChipAvailable;

	UPROPERTY(BlueprintReadOnly, Category="FortResurrectionUIData")
	bool bResurrectionChipPickedUp;

	UPROPERTY(BlueprintReadOnly, Category="FortResurrectionUIData")
	bool bResurrectionChipRebooting;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaPlayerInfoBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerState(AFortPlayerStateAthena* InPlayerState);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle DBNO State Changed"))
	void BP_HandleDBNOStateChanged(bool bDBNO);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Game Mode Icon Changed"))
	void BP_HandleGameModeIconChanged(UTexture2D* GameModeIcon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Is Being Revived State Changed"))
	void BP_HandleIsBeingRevivedStateChanged(bool bIsTalking);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Muted State Changed"))
	void BP_HandleMutedStateChanged(bool bIsMuted);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Player Name Replicated"))
	void BP_HandlePlayerNameReplicated(const FString& PlayerName);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Playlist Extension Widget Created"))
	void BP_HandlePlaylistExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Playlist Loaded"))
	void BP_HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Resurrection State Changed"))
	void BP_HandleResurrectionStateChanged(const FFortResurrectionUIData& ResurrectionStateData);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Season Level UI Display Changed"))
	void BP_HandleSeasonLevelUIDisplayChanged(int32 Level);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Talking State Changed"))
	void BP_HandleTalkingStateChanged(bool bIsTalking);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Talking Visual Display Changed"))
	void BP_HandleTalkingVisualDisplayChanged(bool bTalkingVisualsActive);

	UFUNCTION()
	void HandlePlayerMutatorDataChanged();

	UFUNCTION()
	void HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlayerInfoBase")
	TWeakObjectPtr<AFortPlayerStateAthena> WeakPSA;

private:
	UPROPERTY(EditAnywhere, Category="AthenaPlayerInfoBase")
	bool bIsLocalPlayer;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerInfoBase")
	FSlateColor Color_PlayerNameAlive;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerInfoBase")
	FSlateColor Color_PlayerNameDead;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerInfoBase")
	FSlateColor Color_PlayerNameDisconnected;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_TeamMemberInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_HealthBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ShieldBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UContentWidget> Content_StormCN;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_StormCN;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DBNOBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Marker;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaTeamMemberDBNOState> DBNOStateWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DeadIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DisconnectedIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ResurrectChip;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ResurrectionChipExpirationBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> WidgetSwitcher_Avatar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Icon_AvatarSocial;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_AvatarOverride;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIconProxyAnim> SpeakerWidgetAnim;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaLevelEffects> LevelEffects;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerInfoBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_HealthAndShieldInfo;

};

