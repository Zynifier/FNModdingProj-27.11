// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortGamepadCustomListItem.generated.h"

UCLASS(Abstract)
class UFortGamepadCustomListItem : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

};

