// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortHelpTreeItemBase.generated.h"

class UFortHelpItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHelpTreeItemBase : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortHelpTreeItemBase")
	TObjectPtr<UFortHelpItem> HelpItem;

};

