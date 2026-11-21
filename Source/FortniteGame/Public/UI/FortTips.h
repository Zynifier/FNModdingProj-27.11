// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTips.generated.h"

UENUM()
enum class EFortTipDisplayPlatformGroup : uint8
{
	None = 0,
	Desktop = 1,
	Console = 2,
	Switch = 4,
	Mobile = 8,
};

UCLASS(MinimalAPI)
class UFortTips : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tip")
	TArray<FText> Tips;

protected:
	UPROPERTY(EditAnywhere, Category="Importance")
	bool OverrideTips;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Platform")
	bool DisplayOnPlatformPC;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Platform")
	bool DisplayOnPlatformConsole;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Platform")
	bool DisplayOnPlatformSwitch;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Platform")
	bool DisplayOnPlatformMobile;
#endif

	UPROPERTY()
	uint32 DisplayOnPlatforms;

};

