// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "FortQuestItemDefComponentWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentWidget : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortQuestItemDefComponentWidget", meta=(BaseStruct="/Script/FortniteEditor.QuestItemDefComponentEditorData", ExcludeBaseStruct))
	FInstancedStruct QuestItemDefComponentEditorData;

};

