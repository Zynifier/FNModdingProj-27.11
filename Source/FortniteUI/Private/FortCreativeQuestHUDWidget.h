// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "FortCreativeQuestHUDWidget.generated.h"

class UCommonTextBlock;
class UCreativeQuestComponent;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeQuestHUDWidget : public UMinigameWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestChanged(UCreativeQuestComponent* CurrentQuestComponent, bool bHasActiveQuest);

	UFUNCTION(BlueprintCallable)
	void SetQuestIndex(int32 newQuestIndex);

	UFUNCTION(BlueprintCallable)
	void SetToQuest(int32 questIndex, const bool bForceUpdate = false);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeQuestComponent> LastKnownQuestComponent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeQuestHUDWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CurrentAmount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeQuestHUDWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TargetAmount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeQuestHUDWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeQuestHUDWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestDetails;

	UPROPERTY(EditAnywhere, Category="FortCreativeQuestHUDWidget")
	int32 QuestIndex;

};

