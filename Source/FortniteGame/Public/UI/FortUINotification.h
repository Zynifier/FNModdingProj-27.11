// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "FortUINotification.generated.h"

class UFortUINotification;
class UObject;
enum class EFortNotificationPriority : uint8;
enum class EFortNotificationType : uint8;

UENUM(BlueprintType)
enum class EFortNotificationPriority : uint8
{
	Vote = 0,
	Friend = 1,
	BoostedXP = 2,
	GeneralSendNotification = 3,
	Max = 4,
};

UENUM(BlueprintType)
enum class EFortNotificationType : uint8
{
	Default = 0,
	Power = 1,
	HealthWarning = 2,
	Error = 3,
	GiftSent = 4,
	VoiceChannel = 5,
	DonutChallenge = 6,
	SocialNotification = 7,
	BattlePassPageUnlock = 8,
	DownloadOnDemandError = 9,
	Max = 10,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortUINotificationClearedDelegate, UFortUINotification*, ClearedNotification);

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortUINotification : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintCosmetic, Category="Notification")
	FORTNITEGAME_API void ClearNotification();

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API const FText& GetDescription() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API const TSoftObjectPtr<UObject>& GetDisplayAsset() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API float GetDisplayTimeOverride() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API const FUniqueNetIdRepl& GetIdToRepresent() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API EFortNotificationType GetNotificationType() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API EFortNotificationPriority GetPriority() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API const FText& GetTitle() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool HasAction() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsLongNotification() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintCosmetic, Category="Notification")
	FORTNITEGAME_API void NotificationShown();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetDescription(const FText& InDescription);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetDisplayAsset(const TSoftObjectPtr<UObject>& InDisplayAsset);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetDisplayTimeOverride(const float InDisplayTimeOverride);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetHasAction(const bool bInHasAction);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetIdToRepresent(const FUniqueNetIdRepl& InIdToRepresent);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetIsLongNotification(const bool bInIsLongNotification);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetNotificationType(const EFortNotificationType InNotificationType);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetPriority(const EFortNotificationPriority InPriority);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetTitle(const FText& InTitle);

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Notification")
	FORTNITEGAME_API bool ShouldShowNotification() const;

	UFUNCTION(BlueprintCallable, Category="Notification")
	FORTNITEGAME_API virtual void TakeAction();

	UPROPERTY(BlueprintAssignable, Category="Notification")
	FFortUINotificationClearedDelegate OnNotificationCleared;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetTitle, BlueprintSetter=SetTitle, Category="FortUINotification")
	FText Title;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetDescription, BlueprintSetter=SetDescription, Category="FortUINotification")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetNotificationType, BlueprintSetter=SetNotificationType, Category="FortUINotification")
	EFortNotificationType NotificationType;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetDisplayAsset, BlueprintSetter=SetDisplayAsset, Category="FortUINotification")
	TSoftObjectPtr<UObject> DisplayAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=HasAction, BlueprintSetter=SetHasAction, Category="FortUINotification")
	bool bHasAction;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=IsLongNotification, BlueprintSetter=SetIsLongNotification, Category="FortUINotification")
	bool bIsLongNotification;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetPriority, BlueprintSetter=SetPriority, Category="FortUINotification")
	EFortNotificationPriority Priority;

	UPROPERTY(BlueprintGetter=GetIdToRepresent, BlueprintSetter=SetIdToRepresent, Category="FortUINotification")
	FUniqueNetIdRepl IdToRepresent;

	UPROPERTY(BlueprintGetter=GetDisplayTimeOverride, BlueprintSetter=SetDisplayTimeOverride, Category="FortUINotification", meta=(ClampMin="-1.000000"))
	float DisplayTimeOverride;

};

