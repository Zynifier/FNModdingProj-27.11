// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "Athena/Modifiers/FortAthenaMutator_PerkSystemMutator.h"
#include "InfiltrationPerkSelectContainerWidget.generated.h"

class UInfiltrationPerkSelectionPanel;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationPerkSelectContainerWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool PerkSelectionEnabled() const;

protected:
	UPROPERTY(EditAnywhere, Category="InfiltrationPerkSelectContainerWidget")
	TSubclassOf<UInfiltrationPerkSelectionPanel> PerkPanelClass;

	UPROPERTY()
	FPerkMutatorData MutatorData;

};

