// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modals/AthenaProgressModal.h"
#include "AthenaControllerDisconnectedModal.generated.h"

class UHorizontalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaControllerDisconnectedModal : public UAthenaProgressModal
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_SwitchUser;

};

