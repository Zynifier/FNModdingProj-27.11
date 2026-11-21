// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortLocalUserEntry.generated.h"

class UFortLocalUserSettingsMenu;
class UFortSocialAvatarIcon;
class UImage;
class UMenuAnchor;
class UTextBlock;
class UUserWidget;
enum class ELocalUserOnlineStatus : uint8;

UCLASS(Abstract)
class UFortLocalUserEntry : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	UUserWidget* HandleGetMenuContent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOnlineStatusChanged(ELocalUserOnlineStatus OnlineStatus);

	UPROPERTY(EditAnywhere, Category="FortLocalUserEntry")
	TSubclassOf<UFortLocalUserSettingsMenu> LocalUserSettingsMenuClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLocalUserSettingsMenu> LocalUserSettingsMenu;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> SocialAvatarIcon;

private:
	UFUNCTION()
	void HandleMenuOpenChanged(bool bIsOpen);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Crown;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_UserName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_VoiceChannel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> MenuAnchor_LocalUserSettingMenu;

};

