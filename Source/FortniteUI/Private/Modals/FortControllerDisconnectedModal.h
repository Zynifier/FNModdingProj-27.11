// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modals/FortProgressModal.h"
#include "FortControllerDisconnectedModal.generated.h"

class UHorizontalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortControllerDisconnectedModal : public UFortProgressModal
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_SwitchUser;

};

