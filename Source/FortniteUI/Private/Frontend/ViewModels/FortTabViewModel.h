// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/TopBar/AthenaTopBar.h"
#include "UIKit/ViewModels/UIKitTabGroupButtonViewModel.h"
#include "FortTabViewModel.generated.h"

enum class EFortBangType : uint8;
enum class EFortTopBarTabButtonGroup : uint8;
enum class EFortUIFeature : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="Fort Tab Viewmodel"))
class UFortTabViewModel : public UUIKitTabGroupButtonViewModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortBangType GetBangType() const;

	UFUNCTION(BlueprintPure)
	EFortTopBarTabButtonGroup GetButtonGroup() const;

	UFUNCTION(BlueprintPure)
	EFortUIFeature GetLinkedUIFeature() const;

	UPROPERTY(BlueprintReadWrite, Category="FortTabViewModel")
	bool bEnabled;

	UPROPERTY(BlueprintReadWrite, Category="FortTabViewModel")
	bool bCollapsed;

protected:
	UPROPERTY(Transient)
	FFortTopBarTabButtonInfo TabInfo;

};

