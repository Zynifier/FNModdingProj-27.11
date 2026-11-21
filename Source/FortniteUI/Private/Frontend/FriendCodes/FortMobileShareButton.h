// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortMobileShareButton.generated.h"

enum class EFortFortMobileShareButtonOS : uint8;

UENUM(BlueprintType)
enum class EFortFortMobileShareButtonOS : uint8
{
	Android = 0,
	iOS = 1,
};

UCLASS(Abstract)
class UFortMobileShareButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOSImageEnumSet(EFortFortMobileShareButtonOS OSType);

	UFUNCTION()
	void SetShareParams(const FString& url, const FText& description);

};

