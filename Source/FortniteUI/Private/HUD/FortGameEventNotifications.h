// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortGameEventNotifications.generated.h"

class UFortNotificationEntry;
class UFortQuestObjectiveInfo;
class UVerticalBox;

USTRUCT(BlueprintType)
struct FNotificationWidgetClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="NotificationWidgetClass")
	TSubclassOf<UFortNotificationEntry> NotificationWidgetClass;

	UPROPERTY(EditAnywhere, Category="NotificationWidgetClass")
	int32 InitialPoolSize;

	UPROPERTY(EditAnywhere, Category="NotificationWidgetClass")
	bool bCanIncreasePoolSizeAtRunTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNotificationEntry>> WidgetPool;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortGameEventNotifications : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quests", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortNotificationEntry> DefaultEntryClass;

protected:
	UFUNCTION()
	void ActionFreedForNotifications(FName ActionName);

	UFUNCTION()
	void HandleDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool DisplayStatusUpdate, bool DisplayAnnouncementUpdate);

	UFUNCTION()
	void HandleNotificationUpdateFinished();

	UPROPERTY(Transient)
	bool bHasPrioritizedWidgetFocus;

	UPROPERTY(EditAnywhere, Category="Quests")
	bool bShowFeatQuests;

	UPROPERTY(EditAnywhere, Category="Quests")
	bool bFeatShowNonVisibleObjectives;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortNotificationEntry> ActiveWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNotificationEntry>> WidgetQueue;

	UPROPERTY(Transient)
	TArray<UFortQuestObjectiveInfo*> ObjectivesQueue;

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> NotificationUpdatesBox;

	UPROPERTY(EditAnywhere, Category="Quests")
	TArray<FNotificationWidgetClass> NotificationClassPoolData;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

