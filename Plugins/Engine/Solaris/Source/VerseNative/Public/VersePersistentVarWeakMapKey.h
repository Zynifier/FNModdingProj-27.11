// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VersePersistentVarWeakMapKey.generated.h"

// Base type of `persistent` `var` `weak_map` keys.  To implement a `persistent`
// `var` `weak_map` key, this type should be inherited from and the
// corresponding Verse type should specify `persistent` and
// `module_scoped_var_weak_map_key` in the `class` macro position, e.g.
// `class<persistent><module_scoped_var_weak_map_key>`.

UCLASS(Abstract)
class VERSENATIVE_API UVersePersistentVarWeakMapKey : public UObject
{
	GENERATED_BODY()

};

