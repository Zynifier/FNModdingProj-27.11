// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/ComponentUI/FortQuestItemDefComponentTabbedView.h"
#include "FortQuestItemDefComponentObjectiveExtensionTabbedView.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentObjectiveExtensionTabbedView : public UFortQuestItemDefComponentTabbedView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetObjectiveBackEndName(const FName InObjectiveBackendName);

};

