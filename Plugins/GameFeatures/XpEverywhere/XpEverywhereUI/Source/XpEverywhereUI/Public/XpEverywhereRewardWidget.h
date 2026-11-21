// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "XpEverywhereRewardWidget.generated.h"

class UFortNotificationEntry;
class UVerticalBox;

USTRUCT(BlueprintType)
struct FXpEverywhereNotificationWidgetClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="XpEverywhereNotificationWidgetClass")
	TSubclassOf<UFortNotificationEntry> NotificationWidgetClass;

	UPROPERTY(EditAnywhere, Category="XpEverywhereNotificationWidgetClass")
	int32 InitialPoolSize;

	UPROPERTY(EditAnywhere, Category="XpEverywhereNotificationWidgetClass")
	bool bCanIncreasePoolSizeAtRunTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNotificationEntry>> WidgetPool;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UXpEverywhereRewardWidget : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quests", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortNotificationEntry> DefaultEntryClass;

protected:
	UFUNCTION()
	void HandleNotificationUpdateFinished();

	UPROPERTY(Transient)
	bool bHasPrioritizedWidgetFocus;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortNotificationEntry> ActiveWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNotificationEntry>> WidgetQueue;

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> NotificationUpdatesBox;

	UPROPERTY(EditDefaultsOnly, Category="XpEverywhereRewardWidget")
	TArray<FXpEverywhereNotificationWidgetClass> NotificationClassPoolData;

	UPROPERTY(EditDefaultsOnly, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

