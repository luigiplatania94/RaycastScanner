// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaycastScannerPlugin/Public/RaycastBasedScanner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaycastBasedScanner() {}
// Cross Module References
	RAYCASTSCANNERPLUGIN_API UClass* Z_Construct_UClass_URaycastBasedScanner_NoRegister();
	RAYCASTSCANNERPLUGIN_API UClass* Z_Construct_UClass_URaycastBasedScanner();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RaycastScannerPlugin();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
// End Cross Module References
	static FName NAME_URaycastBasedScanner_OnMetricUpdate = FName(TEXT("OnMetricUpdate"));
	void URaycastBasedScanner::OnMetricUpdate()
	{
		ProcessEvent(FindFunctionChecked(NAME_URaycastBasedScanner_OnMetricUpdate),NULL);
	}
	void URaycastBasedScanner::StaticRegisterNativesURaycastBasedScanner()
	{
	}
	struct Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// This event can be overriden in the blueprint child and it can be used to set the RTPC with the updated metrics.\n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "This event can be overriden in the blueprint child and it can be used to set the RTPC with the updated metrics." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URaycastBasedScanner, nullptr, "OnMetricUpdate", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URaycastBasedScanner_NoRegister()
	{
		return URaycastBasedScanner::StaticClass();
	}
	struct Z_Construct_UClass_URaycastBasedScanner_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AzimuthRayLength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AzimuthRayLength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartingPointOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_StartingPointOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tolerance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Tolerance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDebugVisualisation_MetaData[];
#endif
		static void NewProp_bDebugVisualisation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDebugVisualisation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDebugMetrics_MetaData[];
#endif
		static void NewProp_bDebugMetrics_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDebugMetrics;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PessimisticAzimuthValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PessimisticAzimuthValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OptimisticAzimuthValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OptimisticAzimuthValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaycastBasedScanner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_RaycastScannerPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URaycastBasedScanner_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URaycastBasedScanner_OnMetricUpdate, "OnMetricUpdate" }, // 1684426299
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "RaycastBasedScanner.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_AzimuthRayLength_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Setup" },
		{ "Comment", "// Maximum length of the raycast in the azimuth plane\n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "Maximum length of the raycast in the azimuth plane" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_AzimuthRayLength = { "AzimuthRayLength", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, AzimuthRayLength), METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_AzimuthRayLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_AzimuthRayLength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Setup" },
		{ "Comment", "// The users can specify their own collision channel \n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "The users can specify their own collision channel" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_CollisionChannel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_CollisionChannel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Setup" },
		{ "ClampMax", "0.5" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// User-defined Tick interval. \n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "User-defined Tick interval." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, UpdateInterval), METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_UpdateInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_UpdateInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_StartingPointOffset_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Setup" },
		{ "Comment", "// Offset the height of the starting point of the raycast scanner.\n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "Offset the height of the starting point of the raycast scanner." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_StartingPointOffset = { "StartingPointOffset", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, StartingPointOffset), METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_StartingPointOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_StartingPointOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_Tolerance_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Setup" },
		{ "Comment", "// The system does not measure if the parent actor changed it's position within this specified error limits\n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "The system does not measure if the parent actor changed it's position within this specified error limits" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_Tolerance = { "Tolerance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, Tolerance), METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_Tolerance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_Tolerance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Debug" },
		{ "Comment", "// If TRUE draw circles around the player (Green = Pessimistic. Blue = Optimistic) and draw a sphere on the raycast's starting point. \n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "If TRUE draw circles around the player (Green = Pessimistic. Blue = Optimistic) and draw a sphere on the raycast's starting point." },
	};
#endif
	void Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation_SetBit(void* Obj)
	{
		((URaycastBasedScanner*)Obj)->bDebugVisualisation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation = { "bDebugVisualisation", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(URaycastBasedScanner), &Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation_SetBit, METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics_MetaData[] = {
		{ "Category", "Raycast-Based Scanner | Debug" },
		{ "Comment", "// If TRUE print to the screen both the optimistic and pessimistic metric\n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "If TRUE print to the screen both the optimistic and pessimistic metric" },
	};
#endif
	void Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics_SetBit(void* Obj)
	{
		((URaycastBasedScanner*)Obj)->bDebugMetrics = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics = { "bDebugMetrics", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(URaycastBasedScanner), &Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics_SetBit, METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_PessimisticAzimuthValue_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "RaycastBasedScanner" },
		{ "Comment", "// Final metrics\n" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
		{ "ToolTip", "Final metrics" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_PessimisticAzimuthValue = { "PessimisticAzimuthValue", nullptr, (EPropertyFlags)0x0040000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, PessimisticAzimuthValue), METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_PessimisticAzimuthValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_PessimisticAzimuthValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_OptimisticAzimuthValue_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "RaycastBasedScanner" },
		{ "ModuleRelativePath", "Public/RaycastBasedScanner.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_OptimisticAzimuthValue = { "OptimisticAzimuthValue", nullptr, (EPropertyFlags)0x0040000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URaycastBasedScanner, OptimisticAzimuthValue), METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_OptimisticAzimuthValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_OptimisticAzimuthValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URaycastBasedScanner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_AzimuthRayLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_CollisionChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_UpdateInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_StartingPointOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_Tolerance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugVisualisation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_bDebugMetrics,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_PessimisticAzimuthValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaycastBasedScanner_Statics::NewProp_OptimisticAzimuthValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaycastBasedScanner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaycastBasedScanner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URaycastBasedScanner_Statics::ClassParams = {
		&URaycastBasedScanner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_URaycastBasedScanner_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_URaycastBasedScanner_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URaycastBasedScanner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URaycastBasedScanner()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URaycastBasedScanner_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URaycastBasedScanner, 1628407693);
	template<> RAYCASTSCANNERPLUGIN_API UClass* StaticClass<URaycastBasedScanner>()
	{
		return URaycastBasedScanner::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URaycastBasedScanner(Z_Construct_UClass_URaycastBasedScanner, &URaycastBasedScanner::StaticClass, TEXT("/Script/RaycastScannerPlugin"), TEXT("URaycastBasedScanner"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaycastBasedScanner);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
