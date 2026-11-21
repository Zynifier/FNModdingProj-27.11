// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "FortQuestObjectiveFilterEditor.generated.h"

class UCustomPropertyView;
class UFortQuestItemDefinition;

UCLASS()
class UFortQuestObjectiveFilterEditor : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DuplicateObjectiveFilter();

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveFilterDataSet();

	UFUNCTION(BlueprintCallable)
	void RemoveObjectiveFilter();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestObjectiveFilterEditor", meta=(BindWidget, EditInline="true"))
	UCustomPropertyView* CustomPropertyView_Type;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestObjectiveFilterEditor", meta=(BindWidget, EditInline="true"))
	UCustomPropertyView* CustomPropertyView_Properties;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestObjectiveFilterEditor", meta=(BindWidget, EditInline="true"))
	UCustomPropertyView* CustomPropertyView_ProgressingPlayer;

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItemDefinition> QuestItem;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortQuestObjectiveFilterEditor")
	int32 ObjectiveIdx;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortQuestObjectiveFilterEditor")
	int32 ObjectiveFilterIdx;

};

