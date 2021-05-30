// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RAYCASTSCANNERPLUGIN_RaycastBasedScanner_generated_h
#error "RaycastBasedScanner.generated.h already included, missing '#pragma once' in RaycastBasedScanner.h"
#endif
#define RAYCASTSCANNERPLUGIN_RaycastBasedScanner_generated_h

#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_SPARSE_DATA
#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_RPC_WRAPPERS
#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_RPC_WRAPPERS_NO_PURE_DECLS
#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURaycastBasedScanner(); \
	friend struct Z_Construct_UClass_URaycastBasedScanner_Statics; \
public: \
	DECLARE_CLASS(URaycastBasedScanner, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RaycastScannerPlugin"), NO_API) \
	DECLARE_SERIALIZER(URaycastBasedScanner)


#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_INCLASS \
private: \
	static void StaticRegisterNativesURaycastBasedScanner(); \
	friend struct Z_Construct_UClass_URaycastBasedScanner_Statics; \
public: \
	DECLARE_CLASS(URaycastBasedScanner, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RaycastScannerPlugin"), NO_API) \
	DECLARE_SERIALIZER(URaycastBasedScanner)


#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URaycastBasedScanner(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URaycastBasedScanner) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URaycastBasedScanner); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URaycastBasedScanner); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URaycastBasedScanner(URaycastBasedScanner&&); \
	NO_API URaycastBasedScanner(const URaycastBasedScanner&); \
public:


#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URaycastBasedScanner(URaycastBasedScanner&&); \
	NO_API URaycastBasedScanner(const URaycastBasedScanner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URaycastBasedScanner); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URaycastBasedScanner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(URaycastBasedScanner)


#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PessimisticAzimuthValue() { return STRUCT_OFFSET(URaycastBasedScanner, PessimisticAzimuthValue); } \
	FORCEINLINE static uint32 __PPO__OptimisticAzimuthValue() { return STRUCT_OFFSET(URaycastBasedScanner, OptimisticAzimuthValue); }


#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_27_PROLOG
#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_SPARSE_DATA \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_RPC_WRAPPERS \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_INCLASS \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_SPARSE_DATA \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RAYCASTSCANNERPLUGIN_API UClass* StaticClass<class URaycastBasedScanner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_RaycastScannerPlugin_Source_RaycastScannerPlugin_Public_RaycastBasedScanner_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
