// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortBotNameSettings.generated.h"

UENUM()
namespace EBotNamingMode
{
	enum Type
	{
		RealName = 0,
		SkinName = 1,
		Anonymous = 2,
		Custom = 3,
		CharacterDataDisplayName = 4,
		CustomIncremental = 5,
	};
}

UCLASS(EditInlineNew, MinimalAPI, BlueprintType, Blueprintable)
class UFortBotNameSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortBotNameSettings")
	TEnumAsByte<EBotNamingMode::Type> NamingMode;

	UPROPERTY(EditDefaultsOnly, Category="FortBotNameSettings")
	FText OverrideName;

	UPROPERTY(EditDefaultsOnly, Category="FortBotNameSettings")
	bool bAddPlayerIDSuffix;

};

