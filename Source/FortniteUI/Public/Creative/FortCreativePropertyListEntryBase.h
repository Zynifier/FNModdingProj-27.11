// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonActivatableWidget.h"
#include "FortCreativePropertyListEntryBase.generated.h"

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortCreativePropertyListEntryBase : public UCommonActivatableWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

};

