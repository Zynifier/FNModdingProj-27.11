// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonUserWidget.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "FortVoiceChannelSpeakerWidget.generated.h"

class UCommonBorder;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortSocialAvatarIcon;
class UFortVoiceChannelSpeakerWidget;
class UFortVoiceSpeakerContainerWidget;
class UImage;
class UPanelWidget;
class UWidgetAnimation;
enum class EChannelSpeakerStyle : uint8;

UENUM(BlueprintType)
enum class EChannelSpeakerStyle : uint8
{
	InGame = 0,
	InLobby = 1,
	OutOfClient = 2,
	Max = 3,
};

UCLASS(Abstract, Config=Game)
class UFortBacchusSpeakerWrapper : public UBacchusHUDElement
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceSpeakerContainerWidget> WrappedSpeakers;

};

UCLASS(Abstract, Config=Game)
class UFortVoiceChannelSpeakerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortVoiceChannelSpeakerWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStyleAssigned(EChannelSpeakerStyle NewStyle);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAnimateTalkingChanged(bool bIsNowTalking);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVoiceChannelSpeakerWidget", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Close;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVoiceChannelSpeakerWidget", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Open;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChannelSpeakerWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChannelSpeakerWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChannelName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_ScaleBound;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> AvatarIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ActiveVoiceIcon;

private:
	UFUNCTION()
	void HandleAnimationFinished();

	UPROPERTY(Config)
	float ToleratedSilenceDelay;

	UPROPERTY(EditAnywhere, Category="FortVoiceChannelSpeakerWidget")
	float PerfUpdateIntervalInSecs;

	UPROPERTY(EditAnywhere, Category="FortVoiceChannelSpeakerWidget")
	float OpenCloseAnimProxyDuration;

	UPROPERTY(EditAnywhere, Category="FortVoiceChannelSpeakerWidget")
	bool bPerfCollapseHorizontal;

	UPROPERTY(EditAnywhere, Category="FortVoiceChannelSpeakerWidget")
	float TalkingAnimProxyDuration;

};

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortVoiceSpeakerContainerWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortVoiceSpeakerContainerWidget")
	TSubclassOf<UFortVoiceChannelSpeakerWidget> CustomSpeakerWidgetClass;

private:
	UPROPERTY(Config)
	int32 MaxSimultaneousUsers;

	UPROPERTY(Config)
	bool bShowIndicatorsForSquadMembers;

	UPROPERTY(Config)
	bool bCurrentChannelDisplayEnabled;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortVoiceChannelSpeakerWidget"))
	TObjectPtr<UDynamicEntryBox> DynamicEntry_Speakers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_ChannelContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChannelDisplayName;

};

