// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortToastDisplayArea.generated.h"

class UFortSocialNotificationWidget;
class UFortToastWidget;
class UFortUINotification;
class UFortUINotificationQueue;
class UFortVoiceChannelChangePopup;
enum class EFortNotificationType : uint8;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortToastDisplayArea : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RegisterToastHandler();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void TestBasicToast(const EFortNotificationType InNotificationType, const FText InTitle, const FText InDescription) const;

private:
	UFUNCTION()
	void HandleNewToastAvailable();

	UFUNCTION()
	void HandleToastFinished();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortToastWidget> ToastWidget_New;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortToastWidget> Toast_BattlePassPageUnlocked;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortToastWidget> PowerToastWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortToastWidget> ToastWidget_MinorError;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChannelChangePopup> VoiceChannelChangePopup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortToastWidget> ToastWidgetDonut;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialNotificationWidget> ToastSocialWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortToastDisplayArea", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialNotificationWidget> ToastSocialWidget_New;

	UPROPERTY(Transient)
	TObjectPtr<UFortUINotificationQueue> NotificationQueue;

	UPROPERTY(Transient)
	TObjectPtr<UFortUINotification> CurrentNotification;

};

