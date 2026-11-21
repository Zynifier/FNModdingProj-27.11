// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "AthenaProfileStatListWidgetBase.generated.h"

class UAthenaBaseStatView;
class UAthenaProfileStatBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaProfileStatListWidgetBase : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="UAthenaStatWidgetBase")
	void OnStatChanged();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaProfileStatListWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaProfileStatBox> ProfileStatBox;

private:
	UFUNCTION()
	void HandleStatViewChanged(UAthenaBaseStatView* StatView);

};

