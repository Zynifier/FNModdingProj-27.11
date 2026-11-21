// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_AssistedPlayer.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortNotificationEntry_AssistedPlayer : public UFortNotificationEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_AssistedPlayer", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

};

