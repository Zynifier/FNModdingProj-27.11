// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortSelectableAttributeListItem_NUI.generated.h"

class UFortAttributeListItem_NUI;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSelectableAttributeListItem_NUI : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortAttributeListItem", meta=(EditInline="true"))
	TObjectPtr<UFortAttributeListItem_NUI> AttributeListItem;

};

