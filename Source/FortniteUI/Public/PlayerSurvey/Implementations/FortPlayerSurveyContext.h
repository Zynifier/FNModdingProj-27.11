// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortPlayerSurveyContext.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortPlayerSurveyContextRequestDelegate);

UCLASS(BlueprintType)
class FORTNITEUI_API UFortPlayerSurveyContext : public UBlueprintContextBase
{
	GENERATED_BODY()

};

