// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaPreserveSquadButton.generated.h"

class UCommonButtonBase;

UCLASS(Abstract)
class UAthenaPreserveSquadButton : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Preserve Squad Changed"))
	void BP_HandlePreserveSquadChanged(bool bPreserveSquad);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPreserveSquadButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Internal;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Preserve Squad"))
	bool bDesignTime_PreserveSquad;
#endif

};

