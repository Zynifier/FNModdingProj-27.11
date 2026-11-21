// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Engine/DeveloperSettings.h"
#include "FortniteUserInterfaceSettings.generated.h"

UCLASS(Config=Game)
class FORTNITEENGINELOADINGSCREEN_API UFortniteUserInterfaceSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling", meta=(XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve WidthScaleCurve;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling", meta=(XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve HeightScaleCurve;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - IOS - In Game", meta=(DisplayName="Width Scale Curve - iOS - InGame", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve WidthScaleCurve_iOS_InGame;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - IOS - In Game", meta=(DisplayName="Height Scale Curve - iOS - InGame", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve HeightScaleCurve_iOS_InGame;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - IOS - FrontEnd", meta=(DisplayName="Width Scale Curve - iOS - FrontEnd", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve WidthScaleCurve_iOS_FrontEnd;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - IOS - FrontEnd", meta=(DisplayName="Height Scale Curve - iOS - FrontEnd", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve HeightScaleCurve_iOS_FrontEnd;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - Android - In Game", meta=(DisplayName="Width Scale Curve - Android - InGame", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve WidthScaleCurve_Android_InGame;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - Android - In Game", meta=(DisplayName="Height Scale Curve - Android - InGame", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve HeightScaleCurve_Android_InGame;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - Android - FrontEnd", meta=(DisplayName="Width Scale Curve - Android - FrontEnd", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve WidthScaleCurve_Android_FrontEnd;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling - Android - FrontEnd", meta=(DisplayName="Height Scale Curve - Android - FrontEnd", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve HeightScaleCurve_Android_FrontEnd;

};

