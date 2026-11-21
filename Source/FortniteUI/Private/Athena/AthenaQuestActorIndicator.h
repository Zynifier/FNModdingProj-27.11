// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "AthenaQuestActorIndicator.generated.h"

class UFortQuestIconComponent;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaQuestActorIndicator : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaQuestActorIndicator", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_QuestActorBrush;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortQuestIconComponent> QuestIconComponent;

};

