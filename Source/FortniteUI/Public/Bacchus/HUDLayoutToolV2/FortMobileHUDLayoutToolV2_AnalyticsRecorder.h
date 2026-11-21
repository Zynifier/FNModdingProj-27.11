// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Mobile/LayoutProfile/FortMobileHUDProfile.h"
#include "FortMobileHUDLayoutToolV2_AnalyticsRecorder.generated.h"

USTRUCT()
struct FUserAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ActionName;

};

USTRUCT()
struct FUserGenericAction : public FUserAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMobileHUDProfileBase ActiveProfile;

};

USTRUCT()
struct FUserRenameAction : public FUserAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PreviousName;

	UPROPERTY()
	FString NewName;

};

USTRUCT()
struct FUserSelectProfileAction : public FUserAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMobileHUDProfileBase PreviousProfile;

	UPROPERTY()
	FFortMobileHUDProfileBase NewProfile;

};

