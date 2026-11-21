// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticsEventDelegate.generated.h"

class ICosmeticsEventRegistrar;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInternalDynamicDelegate, const TScriptInterface<ICosmeticsEventRegistrar>, EventTarget);

