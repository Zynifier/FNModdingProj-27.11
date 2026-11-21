// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Announcement/FortClientAnnouncement.h"
#include "Announcement/FortClientAnnouncement_Tutorial.h"
#include "BlueprintContextBase.h"
#include "FortTypes.h"
#include "Frontend/FortUITutorialData.h"
#include "FortTutorialContext.generated.h"

class AFortClientAnnouncement;
class UFortQuestItem;
enum class ETutorialType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortTutorialDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateTutorialAnnouncementDelegate, FFortClientAnnouncementData_Tutorial, TutorialData, bool, bShow);

UCLASS()
class FORTNITEUI_API UFortTutorialContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tutorial")
	bool CanStartTutorial(UFortQuestItem* Quest, FName WidgetName, ETutorialType TutorialType);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void ClearTutorialCallouts();

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void ContinueTutorial();

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void DisableTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName = NAME_None, ETutorialType TutorialType = ETutorialType::None);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void EnableTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName = NAME_None, ETutorialType TutorialType = ETutorialType::None);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void FinishTutorial(UFortQuestItem* Quest, FName WidgetName, ETutorialType TutorialType);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void GetHiddenTutorialCallouts(TArray<FName>& WidgetNames);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void GetTutorialCallouts(TArray<FName>& WidgetNames);

	UFUNCTION(BlueprintPure, Category="Tutorial")
	bool GetTutorialData(const FName& TutorialObjectiveName, FFortUITutorialData& OutTutorialData) const;

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void HideTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName = NAME_None, ETutorialType TutorialType = ETutorialType::None);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	bool IsObjectiveNextTutorialObjective(UFortQuestItem* Quest, FName TutorialObjectiveName);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	bool IsTutorialCalloutVisible(FName WidgetName);

	UFUNCTION()
	void OnNewAnnouncementStartedOnClient(AFortClientAnnouncement* NewAnnouncement);

	UFUNCTION(BlueprintPure, Category="Tutorial")
	bool ShouldPromptToSkipTutorial() const;

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void SkipTutorial();

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void StartTutorial(FName WidgetName, ETutorialType TutorialType);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void TryClearingPendingQuest(UFortQuestItem* Quest);

	UFUNCTION(BlueprintPure, Category="Announcement")
	AFortClientAnnouncement* TryGetActivePrimaryAnnouncement() const;

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void UnhideAllTutorialCallouts();

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void UnhideTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName = NAME_None, ETutorialType TutorialType = ETutorialType::None);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void UpdateTutorialAnnouncement(FFortClientAnnouncementData_Tutorial AnnouncementData, bool bShow = true);

	UPROPERTY(BlueprintAssignable, Category="Tutorial")
	FUpdateTutorialAnnouncementDelegate OnUpdateTutorialAnnouncement;

	UPROPERTY(BlueprintAssignable, Category="Announcement")
	FOnNewClientAnnouncementOnClientDelegate OnNewAnnouncementStartedOnClientDelegate;

};

