// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "FortActivityBrowserModeSetListEntry.generated.h"

class UTexture;
enum class EFortInvalidActivityReason : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityBrowserModeSetListEntry : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetIsSavedActivity() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSavedActivitySet(const bool IsSaved);

protected:
	UFUNCTION(BlueprintPure)
	EFortInvalidActivityReason GetInvalidActivityReason() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityNameSet(const FText& ActivityName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartySizeChanged(const int32 PartySize);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

};

