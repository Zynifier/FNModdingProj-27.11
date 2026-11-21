// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaIGMPartyMemberWidget.generated.h"

class UFortPartyMember;
class UFortSocialAvatarIcon;
class UFortVoiceChatStatusIcon;
class USocialNameTextBlock;
class UUserWidget;
enum class EFortPartyMemberLocation : uint8;
enum class EGameReadiness : uint8;
enum class EUIExtensionSlot : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaIGMPartyMemberWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetIsInGameSlot() const;

	UFUNCTION(BlueprintPure)
	bool GetIsLocalPlayerSlot() const;

	UFUNCTION(BlueprintPure)
	virtual bool IsEmptySlot() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Extension Widget Created"))
	void BP_HandleExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsPartyLeaderChanged(bool bIsPartyLeader);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewLocation(EFortPartyMemberLocation NewLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewReadiness(EGameReadiness GameReadiness);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUserSet();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetReset();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AthenaIGMPartyMemberWidget")
	bool bIsLocalPlayerSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaIGMPartyMemberWidget")
	bool bIsInGameSlot;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaIGMPartyMemberWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> AvatarIconWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaIGMPartyMemberWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaIGMPartyMemberWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

	UPROPERTY(Transient)
	TObjectPtr<UFortPartyMember> CachedPartyMember;

};

