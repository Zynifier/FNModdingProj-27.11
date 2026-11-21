// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUD/HudBindingCheckInterface.h"
#include "FortNotificationEntry.generated.h"

class UFortNotificationEntry;

UENUM()
enum class EFortNotificationEntryCompletionStatus : uint8
{
	/** Quest was just given to the player or they haven't made any progress yet. */
	New = 0,
	/** Quest is in progress. */
	Active = 1,
	/** Player has completed the quest. */
	Completed = 2,
	/** For count. */
	MAX = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinishedNotification);

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortNotificationEntry : public UCommonUserWidget, public IHudBindingCheckInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void AddNotificationBackIntoPool();

	UFUNCTION(BlueprintCallable, Category="Quests")
	virtual void FinishNotificationIntro();

	UFUNCTION(BlueprintCallable, Category="Quests")
	virtual void FinishNotificationOutro();

	UFUNCTION()
	void NativeStartNotificationOutro();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void StartNotificationOutro();

	UPROPERTY(BlueprintAssignable)
	FFinishedNotification FinishedDisplayingNotification;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void StartNotificationIntro();

	UPROPERTY(EditAnywhere, Category="FortNotificationEntry")
	float DisplayTime;

	UPROPERTY(EditAnywhere, Category="FortNotificationEntry")
	float MinDisplayTime;

	UPROPERTY(Transient)
	bool bRushDisplay;

	UPROPERTY(Config)
	int32 RushWidgetThreshold;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNotificationEntry>> LinkedNotifications;

};

